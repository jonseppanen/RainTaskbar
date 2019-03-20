SetTitleMatchMode "RegEx"
#Persistent
#SingleInstance force
CoordMode "Mouse", "Screen"
#Include GDIP.ahk
#Include LIB.ahk
#Include Tray.ahk
OnMessage(16666, "taskSwitch")
OnMessage(16667, "openStart")
OnMessage(16668, "replacetaskbar")
OnMessage(16669, "ExitFunc")
OnExit("ExitFunc")
iconCacheDir := EnvGet("USERPROFILE") "\Documents\raintaskbar\"
if(!FileExist(iconCacheDir)){
    DirCreate iconCacheDir
}

loadIconCache(iconCacheDir){
    iconCache := []
    
    Loop Files, iconCacheDir "*.bmp"
    {
        iconCache.push(A_LoopFileName)
    }
    return iconCache
}

loadColorCache(iconCacheDir){
    colorCache := {}
    ColorArray := StrSplit(IniRead(iconCacheDir "colors.ini", "iconColors"), "`n")

    Loop ColorArray.Length()
    {
        thisPair := StrSplit(ColorArray[A_Index], "=")
        colorCache[thisPair[1]] := thisPair[2]
    }

    return colorCache
}

tasklist := []
getSortedWindowList(){
    ids := WinGetList(,, "NxDock|Program Manager|Task Switching|^$")
    sortstring := ""
    windowarray := []
    Global tasklist

    Loop ids.Length()
    {
        WinGetPos(,,, Height,"ahk_id " ids[A_Index])
        if ((WinGetExStyle("ahk_id " ids[A_Index]) & 0x8000088) || !Height || WinGetTitle("ahk_id " ids[A_Index]) = "VirtualDesktopSwitcher" || IsWindowCloaked(ids[A_Index]))
        {
            continue
        }
        sortstring :=  sortstring  WinGetProcessName("ahk_id " ids[A_Index]) ":" ids[A_Index] ","
    }   
    sortarray := StrSplit(Sort(sortstring,"D,"),",")
    Loop sortarray.Length(){
        thisId := StrSplit(sortarray[A_Index],":")
        if(thisId[(thisId.Length())]){
            windowarray.push(thisId[(thisId.Length())])
        }
    } 
    
    tasklist := windowarray
    return tasklist
}

getDominantIconColor(colorCache, taskExeName, hicon){
    Global iconCacheDir
    dominantcolor := ""
    if(!colorCache[taskExeName]){
        dominantcolor := Gdip_Getavg(Gdip_CreateBitmapFromHICON(hicon)) ",255"
        IniWrite dominantcolor, iconCacheDir "colors.ini", "iconColors", taskExeName
    }
    else{
        dominantcolor := colorCache[taskExeName]
    }
    return dominantcolor
}

ActiveHwnd := ""
taskSwitch(wParam, lParam)
{ 
    Global tasklist
    IDVar := tasklist[wParam]
    minMax := WinGetMinMax("ahk_id " IDVar)
    Global ActiveHwnd

    if(minMax < 0){
        WinActivate "ahk_id " IDVar
        ActiveHwnd := IDVar
        return
    }
    else if(ActiveHwnd = IDVar){
        WinMinimize "ahk_id " IDVar
    }
    else{
        WinActivate "ahk_id " IDVar
        ActiveHwnd := IDVar
    }
}

getIconHandle(taskExePath){
    VarSetCapacity(fileinfo, fisize := A_PtrSize + 688)
    if DllCall("shell32\SHGetFileInfoW", "WStr", taskExePath, "UInt", 0, "Ptr", &fileinfo, "UInt", fisize, "UInt", 0x100)
    {
        return NumGet(fileinfo, 0, "Ptr")
    }
}

windowtitles := []
getWindowTitles(){
    Global windowtitles
    Global tasklist
    Loop tasklist.Length()
    {
        thisId := tasklist[A_Index]
        thisTitle := WinGetTitle("ahk_id " thisId)
        if(windowtitles.Length() > 0 && thisTitle = windowtitles[A_Index]){
            continue
        }
        windowtitles[A_Index] := thisTitle

        SendRainmeterCommand("!SetOption MeasureTask" A_Index "WindowTitle String `""  thisTitle  "`" ")
        SendRainmeterCommand("!Updatemeasuregroup measuretask" A_Index "group ")
        SendRainmeterCommand("!Updatemetergroup Task" A_Index "Group ")
        SendRainmeterCommand("!Redrawgroup Task" A_Index "Group ")
    }
}

lastasks := []
getWindows()
{    
    Global iconCacheDir
    iconCache := loadIconCache(iconCacheDir)
    colorCache := loadColorCache(iconCacheDir)
    ids := getSortedWindowList()
    activeid := WinGetID("A")
    Global lastasks


    Loop ids.Length()
    {
        thisId := ids[A_Index]
        if(thisId = activeid){
            SendRainmeterCommand("!SetVariable ActiveTaskNumber " A_Index )
        }

        if(lastasks.Length() > 0 && thisId = lastasks[A_Index]){
            continue
        }
        lastasks[A_Index] := thisId
        
        
        taskExeFullName := WinGetProcessName("ahk_id " thisId)
        taskExeName := StrReplace(taskExeFullName, ".exe", "")
        hicon := getIconHandle(WinGetProcessPath("ahk_id " thisId))
        dominantcolor := getDominantIconColor(colorCache, taskExeName, hicon)
        if(!hasValue(iconCache, taskExeName ".bmp")){
            SaveHICONtoFile( hicon, iconCacheDir taskExeName ".bmp" )
        }
        SendRainmeterCommand("!SetOption MeasureTask" A_Index "Exe String `""  taskExeName  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" A_Index "Color String `""  dominantcolor  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" A_Index "IconPath String `""  iconCacheDir taskExeName ".bmp"  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" A_Index "State  String  `""  WinGetMinMax("ahk_id " thisId)  "`" ")
        SendRainmeterCommand("!Updatemeasuregroup measuretask" A_Index "group ")
        SendRainmeterCommand("!Updatemetergroup Task" A_Index "Group ")
        SendRainmeterCommand("!Redrawgroup Task" A_Index "Group ")
    }

    Loop (16 - ids.Length()){
        SendRainmeterCommand("!SetOption MeasureTask" (ids.Length() +  A_Index) "Exe String NULL")
        SendRainmeterCommand("!Updatemeasuregroup measuretask" (ids.Length() +  A_Index) "group ")
        SendRainmeterCommand("!Updatemetergroup Task" (ids.Length() +  A_Index) "Group ")
        SendRainmeterCommand("!Redrawgroup Task" (ids.Length() +  A_Index) "Group ")
    }
}

SendRainmeterCommand("!SetOption MeasureWindowMessage WindowName `""  A_ScriptDir "\Taskbar.ahk - AutoHotkey v" A_AhkVersion  "`" ")
SendRainmeterCommand("!UpdateMeasure MeasureWindowMessage")
SetTimer "getwindows", 300
SetTimer "getWindowTitles", 300
SetTimer "TrayIcon_GetInfo", 1000
replacetaskbar(A_Args[1],A_Args[2])