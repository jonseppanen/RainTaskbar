; ----------------------------------------------------------------------------------------------------------------------
; Name ..........: TrayIcon library
; Description ...: Provide some useful functions to deal with Tray icons.
; AHK Version ...: AHK_L 1.1.22.02 x32/64 Unicode
; Original Author: Sean (http://goo.gl/dh0xIX) (http://www.autohotkey.com/forum/viewtopic.php?t=17314)
; Update Author .: Cyruz (http://ciroprincipe.info) (http://ahkscript.org/boards/viewtopic.php?f=6&t=1229)
; Mod Author ....: Fanatic Guru
; License .......: WTFPL - http://www.wtfpl.net/txt/copying/
; Version Date...: 2018 03 13
; Note ..........: Many people have updated Sean's original work including me but Cyruz's version seemed the most straight
; ...............: forward update for 64 bit so I adapted it with some of the features from my Fanatic Guru version.
; Update 20160120: Went through all the data types in the DLL and NumGet and matched them up to MSDN which fixed IDcmd.
; Update 20160308: Fix for Windows 10 NotifyIconOverflowWindow
; Update 20180313: Fix problem with "VirtualFreeEx" pointed out by nnnik
; Update 20180313: Additional fix for previous Windows 10 NotifyIconOverflowWindow fix breaking non-hidden icons
; ----------------------------------------------------------------------------------------------------------------------

; ----------------------------------------------------------------------------------------------------------------------
; Function ......: TrayIcon_GetInfo
; Description ...: Get a series of useful information about tray icons.
; Parameters ....: sExeName  - The exe for which we are searching the tray icon data. Leave it empty to receive data for 
; ...............:             all tray icons.
; Return ........: trayIcons - An array of objects containing tray icons data. Any entry is structured like this:
; ...............:             trayIcons[A_Index].idx     - 0 based tray icon index.
; ...............:             trayIcons[A_Index].IDcmd   - Command identifier associated with the button.
; ...............:             trayIcons[A_Index].pID     - Process ID.
; ...............:             trayIcons[A_Index].uID     - Application defined identifier for the icon.
; ...............:             trayIcons[A_Index].msgID   - Application defined callback message.
; ...............:             trayIcons[A_Index].hIcon   - Handle to the tray icon.
; ...............:             trayIcons[A_Index].hWnd    - Window handle.
; ...............:             trayIcons[A_Index].Class   - Window class.
; ...............:             trayIcons[A_Index].Process - Process executable.
; ...............:             trayIcons[A_Index].Tray    - Tray Type (Shell_TrayWnd or NotifyIconOverflowWindow).
; ...............:             trayIcons[A_Index].tooltip - Tray icon tooltip.
; Info ..........: TB_BUTTONCOUNT message - http://goo.gl/DVxpsg
; ...............: TB_GETBUTTON message   - http://goo.gl/2oiOsl
; ...............: TBBUTTON structure     - http://goo.gl/EIE21Z
; ----------------------------------------------------------------------------------------------------------------------

Setting_A_DetectHiddenWindows := A_DetectHiddenWindows

systrayicondir := EnvGet("USERPROFILE") "\Documents\raintaskbar\systray"
if(!FileExist(systrayicondir)){
    DirCreate systrayicondir
}

loadSystrayCache(systrayicondir){
    systrayiconcache := {}
    systrayiconarray := StrSplit(IniRead(systrayicondir "tray.ini", "IconHash"), "`n")

    Loop systrayiconarray.Length()
    {
        thisPair := StrSplit(ColorArray[A_Index], "=")
        systrayiconcache[thisPair[1]] := thisPair[2]
    }

    return systrayiconcache
}

savesystrayhicon(hIconBmp, hWnd){

	Global systrayicondir
	
	iconBitmap := Gdip_CreateBitmapFromHICON(hIconBmp)
	if(!iconBitmap)
	{
		hIconBmp := extractIconFromExe(WinGetProcessPath("ahk_id " hWnd))
		iconBitmap := Gdip_CreateBitmapFromHICON(hIconBmp)
	}
	
	iconPixels := Gdip_GetPixels(iconBitmap)
	iconMD5 := MD5(iconPixels)

	if(!FileExist(systrayicondir "\" sProcess "\" iconMD5)){
		SaveHICONtoFile(hIconBmp,systrayicondir "\" sProcess "\" iconMD5 ".bmp")
	}

}

trayIcons := {}
TrayIcon_GetInfo(sExeName := "")
{
	Global Setting_A_DetectHiddenWindows
	Global systrayicondir
	Global trayIcons
	DetectHiddenWindows "On"
    trayMap := {"Shell_TrayWnd":"User Promoted Notification Area","NotifyIconOverflowWindow":"Overflow Notification Area"}
	Index := 1
    For trayClass,trayTitle in trayMap
	{
		hProc := DllCall("OpenProcess", UInt, 0x38, Int, 0, UInt, WinGetPID("ahk_class " trayClass))
		pRB   := DllCall("VirtualAllocEx", Ptr, hProc, Ptr, 0, UPtr, 20, UInt, 0x1000, UInt, 0x4)
        trayId := "ahk_id " ControlGetHwnd(trayTitle,"ahk_class " trayClass)
        TrayCount := SendMessage(0x418, 0, 0, ,trayId)
		szBtn := VarSetCapacity(btn, (A_Is64bitOS ? 32 : 20), 0)
		szNfo := VarSetCapacity(nfo, (A_Is64bitOS ? 32 : 24), 0)
		szTip := VarSetCapacity(tip, 128 * 2, 0)
		
		
		Loop TrayCount
		{
            SendMessage(0x417, A_Index - 1, pRB, ,trayId)
			DllCall("ReadProcessMemory", Ptr, hProc, Ptr, pRB, Ptr, &btn, UPtr, szBtn, UPtr, 0)

			iBitmap := NumGet(btn, 0, "Int")
			IDcmd   := NumGet(btn, 4, "Int")
			statyle := NumGet(btn, 8)
			dwData  := NumGet(btn, (A_Is64bitOS ? 16 : 12))
			iString := NumGet(btn, (A_Is64bitOS ? 24 : 16), "Ptr")

			DllCall("ReadProcessMemory", Ptr, hProc, Ptr, dwData, Ptr, &nfo, UPtr, szNfo, UPtr, 0)

			hWnd  := NumGet(nfo, 0, "Ptr")
			uID   := NumGet(nfo, (A_Is64bitOS ? 8 : 4), "UInt")
			msgID := NumGet(nfo, (A_Is64bitOS ? 12 : 8))
			hIcon := NumGet(nfo, (A_Is64bitOS ? 24 : 20), "Ptr")
			pID := WinGetPID("ahk_id " hWnd)
			sProcess := WinGetProcessName("ahk_id " hWnd)
			sClass := WinGetClass("ahk_id " hWnd)
			DllCall("ReadProcessMemory", Ptr, hProc, Ptr, iString, Ptr, &tip, UPtr, szTip, UPtr, 0)

			if(sProcess = "TaskMgr.exe" && sToolTip = "Task Manager"){
				continue
			}

			if(hIcon != trayIcons[Index,"hIcon"]){
				hIconBmp := hIcon
				iconBitmap := Gdip_CreateBitmapFromHICON(hIcon)
				if(!iconBitmap)
				{
					hIconBmp := extractIconFromExe(WinGetProcessPath("ahk_id " hWnd))
					iconBitmap := Gdip_CreateBitmapFromHICON(hIconBmp)
				}
				iconPixels := Gdip_GetPixels(iconBitmap)
				iconMD5 := MD5(iconPixels)
				iconavgcolor := Gdip_GetAvg(iconBitmap)

				if(!FileExist(systrayicondir "\" sProcess)){
					DirCreate systrayicondir "\" sProcess
				}

				if(!FileExist(systrayicondir "\" sProcess "\" iconMD5  ".bmp")){
					SaveHICONtoFile(hIconBmp,systrayicondir "\" sProcess "\" iconMD5 ".bmp")
				}

				trayIcons[Index,"Color"]   := iconavgcolor
				trayIcons[Index,"hIcon"]   := hIcon
				trayIcons[Index,"iconMD5"] := iconMD5
				trayIcons[Index,"Path"]    := systrayicondir "\" sProcess "\" iconMD5  ".bmp"
				SendRainmeterCommand("!SetOption MeasureTray" A_Index "Color String `""  iconavgcolor  "`" ")
				SendRainmeterCommand("!SetOption MeasureTray" A_Index "iconpath String `""  trayIcons[Index,"Path"]  "`" ")
			}

			if(sTooltip != trayIcons[Index,"Tooltip"] ){
				trayIcons[Index,"Tooltip"] := sTooltip
				SendRainmeterCommand("!SetOption MeasureTray" A_Index "Tooltip String `""  sTooltip  "`" ")
			}

			if(sProcess != trayIcons[Index,"sProcess"] ){
				trayIcons[Index,"Process"] := sProcess
				SendRainmeterCommand("!SetOption MeasureTray" A_Index "Exe String `""  sProcess  "`" ")
			}

			trayIcons[Index,"idx"]     := A_Index - 1
			trayIcons[Index,"IDcmd"]   := IDcmd
			trayIcons[Index,"pID"]     := pID
			trayIcons[Index,"uID"]     := uID
			trayIcons[Index,"msgID"]   := msgID
			trayIcons[Index,"hWnd"]    := hWnd
			trayIcons[Index,"Class"]   := sClass
			trayIcons[Index,"Process"] := sProcess
			trayIcons[Index,"Tray"]    := trayClass				
			Index++
			
		}
		DllCall("VirtualFreeEx", Ptr, hProc, Ptr, pRB, UPtr, 0, Uint, 0x8000)
		DllCall("CloseHandle", Ptr, hProc)
	}
	Loop (16 - Index){
        SendRainmeterCommand("!SetOption MeasureTray" (Index +  A_Index) "Exe String NULL")
        SendRainmeterCommand("!Updatemeasuregroup measuretray" (Index +  A_Index) "group ")
        SendRainmeterCommand("!Updatemetergroup Tray" (Index +  A_Index) "Group ")
        SendRainmeterCommand("!Redrawgroup Tray" (Index +  A_Index) "Group ")
    }
	DetectHiddenWindows Setting_A_DetectHiddenWindows
	Return trayIcons
}

ClickSystray(wParam, lParam)
{
  if(lParam = 1)
  {
    SendSystrayClick(wParam,"LBUTTONDOWN")
  }
  else if(lParam = 2)
  {
    SendSystrayClick(wParam,"LBUTTONUP")
  }
  else if(lParam = 3)
  {
    SendSystrayClick(wParam,"RBUTTONDOWN")
  }
  else if(lParam = 4)
  {
    SendSystrayClick(wParam,"RBUTTONUP")
  }
}


SendSystrayClick(trayitemindex,  sButton := "LBUTTONUP")
{
	Global trayIcons	
	Global Setting_A_DetectHiddenWindows
	DetectHiddenWindows "On"
	WM_MOUSEMOVE	  := 0x0200
	WM_LBUTTONDOWN	  := 0x0201
	WM_LBUTTONUP	  := 0x0202
	WM_LBUTTONDBLCLK := 0x0203
	WM_RBUTTONDOWN	  := 0x0204
	WM_RBUTTONUP	  := 0x0205
	WM_RBUTTONDBLCLK := 0x0206
	WM_MBUTTONDOWN	  := 0x0207
	WM_MBUTTONUP	  := 0x0208
	WM_MBUTTONDBLCLK := 0x0209
	sButton := "WM_" sButton
	msgID  := trayIcons[trayitemindex].msgID
	uID    := trayIcons[trayitemindex].uID
	hWnd   := trayIcons[trayitemindex].hWnd

	if(trayIcons[trayitemindex].Tooltip = "Safely Remove Hardware and Eject Media" && (sButton := "WM_LBUTTONUP" || sButton := "WM_RBUTTONUP"))
	{
		Run "RunDll32.exe shell32.dll,Control_RunDLL hotplug.dll"
	}
	else
	{
		Sleep 30
		SendMessage(msgID, uID, %sButton%, , "ahk_id " hWnd)
	}
		
	DetectHiddenWindows Setting_A_DetectHiddenWindows
	return
}


OnMessage(16682, "ClickSystray")