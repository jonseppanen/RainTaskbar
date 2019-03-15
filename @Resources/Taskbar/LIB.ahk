IsWindowCloaked(hwnd)
{
    static gwa := DllCall("GetProcAddress", "ptr", DllCall("LoadLibrary", "str", "dwmapi", "ptr"), "astr", "DwmGetWindowAttribute", "ptr")
    return (gwa && DllCall(gwa, "ptr", hwnd, "int", 14, "int*", cloaked, "int", 4) = 0) ? cloaked : 0
}

Send_WM_COPYDATA(ByRef StringToSend, ByRef TargetWindowClass)  
{
    VarSetCapacity(CopyDataStruct, 3*A_PtrSize, 0) 
    SizeInBytes := (StrLen(StringToSend) + 1) * (A_IsUnicode ? 2 : 1)
    NumPut(1, CopyDataStruct) 
    NumPut(SizeInBytes, CopyDataStruct, A_PtrSize)  
    NumPut(&StringToSend, CopyDataStruct, 2*A_PtrSize) 
    SendMessage(0x4a, 0, &CopyDataStruct,, "ahk_class " TargetWindowClass)  
    return ErrorLevel  
}

getThisDirName()
{
    SplitPath A_ScriptDir , , ResourcesDir
    SplitPath ResourcesDir , ,OutFileName3,OutFileName2
    Splitpath OutFileName3 , Skindir
    return Skindir
}

rainmeterThemeDir := getThisDirName()
SendRainmeterCommand(command)
{
    Global rainmeterThemeDir
    
    commandWrap :=  "[" . command . " " . rainmeterThemeDir . "]"
    
    if(Send_WM_COPYDATA(commandWrap, "ahk_class RainmeterMeterWindow") = 1){
        ExitApp
    }
}

hasValue(haystack, needle) 
{
    if(!isObject(haystack))
        return false
    if(haystack.Length()==0)
        return false
    for k,v in haystack
        if(v==needle)
            return true
    return false
}

ExitFunc(ExitReason, ExitCode)
{
    global pToken
    Gdip_Shutdown(pToken)
    RemoveAppbar()
}

Global APPBARDATA
ABM := DllCall( "RegisterWindowMessage", Str,"AppBarMsg", "UInt" )
OnMessage( ABM, "ABM_Callback" )
ABM_Callback( wParam, LParam, Msg, HWnd ) {
; Not much messages received. When Taskbar settings are
; changed the wParam becomes 1, else it is always 2
}

GetTaskBarLocation() {
    Regvalue := RegRead("HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\StuckRects3", "Settings")
    Nr := SubStr(Regvalue, 26, 1)
    Return Nr
}

setdesktoparea(wParam, lParam){
    Global APPBARDATA
    VarSetCapacity( APPBARDATA , (cbAPPBARDATA := A_PtrSize == 8 ? 48 : 36), 0 )
    Off :=  NumPut(  cbAPPBRADATA, APPBARDATA, "Ptr" )
    Off :=  NumPut( hAB, Off+0, "Ptr" )
    Off :=  NumPut( ABM, Off+0, "UInt" )
    Off :=  NumPut(   GetTaskBarLocation(), Off+0, "UInt" ) 
    Off :=  NumPut(  0, Off+0, "Int" ) 
    Off :=  NumPut(  1380 , Off+0, "Int" ) 
    Off :=  NumPut(  wParam, Off+0, "Int" ) 
    Off :=  NumPut(  lParam, Off+0, "Int" )
    Off :=  NumPut(   1, Off+0, "Ptr" )
    DllCall("Shell32.dll\SHAppBarMessage", UInt,(ABM_NEW:=0x0)     , Ptr,&APPBARDATA )
    DllCall("Shell32.dll\SHAppBarMessage", UInt,(ABM_QUERYPOS:=0x2), Ptr,&APPBARDATA )
    DllCall("Shell32.dll\SHAppBarMessage", UInt,(ABM_SETPOS:=0x3)  , Ptr,&APPBARDATA )
}

RemoveAppBar(){
  Global APPBARDATA
  DllCall("Shell32.dll\SHAppBarMessage", UInt,(ABM_REMOVE := 0x1), Ptr,&APPBARDATA )
  WinShow "ahk_class Shell_TrayWnd"
  ExitApp
}

openStart(){
    sendinput "{LWin}"
}

replacetaskbar(wParam, lParam){
    setdesktoparea(wParam, lParam)
    WinHide "ahk_class Shell_TrayWnd"   
}