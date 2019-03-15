;WinMove 0,1440, "ahk_class Shell_TrayWnd"
;WinHide "ahk_class Shell_TrayWnd"
;WinShow "ahk_class Shell_TrayWnd"
Run A_ScriptDir "\taskbar-hider\TaskBarHider.exe -hide -exit"