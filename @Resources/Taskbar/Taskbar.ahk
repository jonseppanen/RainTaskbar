SetTitleMatchMode "RegEx"
#Persistent
#SingleInstance force
CoordMode "Mouse", "Screen"

#Include GDIP.ahk

rainmeterThemeDir := getThisDirName()
taskList := {}
ActiveHwnd := ""

IsWindowCloaked(hwnd)
{
    static gwa := DllCall("GetProcAddress", "ptr", DllCall("LoadLibrary", "str", "dwmapi", "ptr"), "astr", "DwmGetWindowAttribute", "ptr")
    return (gwa && DllCall(gwa, "ptr", hwnd, "int", 14, "int*", cloaked, "int", 4) = 0) ? cloaked : 0
}

taskSwitch(wParam, lParam)
{ 
    Global Tasklist
    
    IDVar := Tasklist[wParam,"ahkid"]
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

getThisDirName()
{
    ;Msgbox A_ScriptDir "\Taskbar.ahk - AutoHotkey v" A_AhkVersion
    SplitPath A_ScriptDir , , ResourcesDir
    SplitPath ResourcesDir , ,OutFileName3,OutFileName2
    Splitpath OutFileName3 , Skindir
    return Skindir
}

loadIconCache(iconCacheDir){
    iconCache := []
    if(!FileExist(iconCacheDir)){
        DirCreate iconCacheDir
    }
    Loop Files, iconCacheDir "*.bmp"
    {
        iconCache.push(A_LoopFileName)
    }
    return iconCache
}

loadColorCache(iconCacheDir){
    colorCache := {}
    if(!FileExist(iconCacheDir)){
        DirCreate iconCacheDir
    }
    ColorArray := StrSplit(IniRead(iconCacheDir "colors.ini", "iconColors"), "`n")

    Loop ColorArray.Length()
    {
        thisPair := StrSplit(ColorArray[A_Index], "=")
        colorCache[thisPair[1]] := thisPair[2]
    }

    return colorCache
}

getWindows()
{    

    Global Tasklist
    Tasklist := {}
    taskString := ""
    iconCacheDir := EnvGet("USERPROFILE") "\Documents\raintaskbar\"
    iconCache := loadIconCache(iconCacheDir)
    colorCache := loadColorCache(iconCacheDir)

    ids := WinGetList(,, "NxDock|Program Manager|Task Switching|^$")
    loopInt := 1

    Loop ids.Length()
    {
        thisId := ids[A_Index]
        WinGetPos(,,, Height,"ahk_id " thisId)

        if ((WinGetExStyle("ahk_id " thisId) & 0x8000088) || !Height || WinGetTitle("ahk_id " thisId) = "VirtualDesktopSwitcher" || IsWindowCloaked(thisId))
        {
            continue
        }

        taskExeName := WinGetProcessName("ahk_id " thisId)
        taskExePath := WinGetProcessPath("ahk_id " thisId)


        VarSetCapacity(fileinfo, fisize := A_PtrSize + 688)
        if DllCall("shell32\SHGetFileInfoW", "WStr", taskExePath, "UInt", 0, "Ptr", &fileinfo, "UInt", fisize, "UInt", 0x100)
        {
            hicon := NumGet(fileinfo, 0, "Ptr")
            hbmp := Gdip_CreateBitmapFromHICON(hicon)
            taskList[loopInt,"hbmp"] := hbmp
        }

        targetExeClass := WinGetClass("ahk_id " thisId)
        taskExeTitle := WinGetTitle("ahk_id " thisId)
        taskExeState := WinGetMinMax("ahk_id " thisId)

        taskList[loopInt,"ahkid"] := thisId
        taskList[loopInt,"indexNumber"] := loopInt
        taskList[loopInt,"taskExeName"] := StrReplace(taskExeName, ".exe", "")
        taskList[loopInt,"taskExePath"] := taskExePath
        taskList[loopInt,"targetExeClass"] := targetExeClass
        taskList[loopInt,"taskExeTitle"] := taskExeTitle

        if(!colorCache[taskList[loopInt,"taskExeName"]]){
            taskList[loopInt, "dominantcolor"] := Gdip_Getavg(hbmp) ",255"
            IniWrite taskList[loopInt, "dominantcolor"], iconCacheDir "colors.ini", "iconColors", taskList[loopInt,"taskExeName"]
        }
        else{
            taskList[loopInt, "dominantcolor"] := colorCache[taskList[loopInt,"taskExeName"]]
        }

        taskList[loopInt, "State"] := taskExeState

        if(!hasValue(iconCache, taskList[loopInt,"taskExeName"] ".bmp")){
            SaveHICONtoFile( hicon, iconCacheDir taskList[loopInt,"taskExeName"] ".bmp" )
        }

        taskList[loopInt, "iconPath"] := iconCacheDir taskList[loopInt,"taskExeName"] ".bmp"

        SendRainmeterCommand("!SetOption MeasureTask" loopInt "Exe String `""  taskList[loopInt,"taskExeName"]  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" loopInt "Color String `""  taskList[loopInt,"dominantcolor"]  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" loopInt "WindowTitle String `""  taskList[loopInt,"taskExeTitle"]  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" loopInt "IconPath String `""  taskList[loopInt,"IconPath"]  "`" ")
        SendRainmeterCommand("!SetOption MeasureTask" loopInt "State  String  `""  taskList[loopInt,"State"]  "`" ")

        loopInt++
    }

    Loop (16 - loopInt){
        SendRainmeterCommand("!SetOption MeasureTask" loopInt "Exe String NULL")
        loopInt++
    }
}

SendRainmeterCommand("!SetOption MeasureWindowMessage WindowName `""  A_ScriptDir "\Taskbar.ahk - AutoHotkey v" A_AhkVersion  "`" ")
SendRainmeterCommand("!UpdateMeasure MeasureWindowMessage")
OnMessage(16666, "taskSwitch")

SetTimer "getwindows", 1000

