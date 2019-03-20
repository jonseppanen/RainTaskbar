;============================================= Initialize Backend ================================================


[MeasureWindowMessage]
UpdateDivider=-1
Measure=Plugin
Plugin=WindowMessagePlugin
WindowName=""
DynamicVariables=1

[MeasureTaskbar]
Measure=Plugin
Plugin=HideTaskbar
BarInstance=Both
DynamicVariables=1

[MeasureRunTaskbar]
UpdateDivider=-1
DynamicVariables=1
Measure=calc
OnUpdateAction=[!CommandMeasure MeasureTaskbar "Hide"][!CommandMeasure MeasureTaskbar "AutoHide"][#@#\Taskbar\Taskbar.exe #@#\Taskbar\Taskbar.ahk "#CURRENTCONFIGWIDTH#" "CURRENTCONFIGHEIGHT"]

[MeasureTaskbarSize]
DynamicVariables=1
Measure=calc
Formula=#CURRENTCONFIGWIDTH# + #CURRENTCONFIGHEIGHT# 
OnChangeAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16668 #CURRENTCONFIGWIDTH# #CURRENTCONFIGHEIGHT#"]

;============================================= Task 1 Measures ================================================


[MeasureTask1Exe]
Measure=String
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task1Group]
IfMatchAction=[!HideMeterGroup Task1Group]
Group=measuretask1group

[MeasureTask1WindowTitle]
Measure=String
Group=measuretask1group

[MeasureTask1Color]
Measure=String
Group=measuretask1group

[MeasureTask1State]
Measure=String
Group=measuretask1group

[MeasureTask1IconPath]
Measure=String
Group=measuretask1group


;============================================= Task 2 Measures ================================================


[MeasureTask2Exe]
Measure=String
Group=measuretask2group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task2Group]
IfMatchAction=[!HideMeterGroup Task2Group]

[MeasureTask2WindowTitle]
Measure=String
Group=measuretask2group

[MeasureTask2Color]
Measure=String
Group=measuretask2group

[MeasureTask2State]
Measure=String
Group=measuretask2group

[MeasureTask2IconPath]
Measure=String
Group=measuretask2group


;============================================= Task 3 Measures ================================================


[MeasureTask3Exe]
Measure=String
Group=measuretask3group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task3Group]
IfMatchAction=[!HideMeterGroup Task3Group]

[MeasureTask3WindowTitle]
Measure=String
Group=measuretask3group

[MeasureTask3Color]
Measure=String
Group=measuretask3group

[MeasureTask3State]
Measure=String
Group=measuretask3group

[MeasureTask3IconPath]
Measure=String
Group=measuretask3group


;============================================= Task 4 Measures ================================================


[MeasureTask4Exe]
Measure=String
Group=measuretask4group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task4Group]
IfMatchAction=[!HideMeterGroup Task4Group]

[MeasureTask4WindowTitle]
Measure=String
Group=measuretask4group

[MeasureTask4Color]
Measure=String
Group=measuretask4group

[MeasureTask4State]
Measure=String
Group=measuretask4group

[MeasureTask4IconPath]
Measure=String
Group=measuretask4group


;============================================= Task 5 Measures ================================================


[MeasureTask5Exe]
Measure=String
Group=measuretask5group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task5Group]
IfMatchAction=[!HideMeterGroup Task5Group]

[MeasureTask5WindowTitle]
Measure=String
Group=measuretask5group

[MeasureTask5Color]
Measure=String
Group=measuretask5group

[MeasureTask5State]
Measure=String
Group=measuretask5group

[MeasureTask5IconPath]
Measure=String
Group=measuretask5group


;============================================= Task 6 Measures ================================================


[MeasureTask6Exe]
Measure=String
Group=measuretask6group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task6Group]
IfMatchAction=[!HideMeterGroup Task6Group]

[MeasureTask6WindowTitle]
Measure=String
Group=measuretask6group

[MeasureTask6Color]
Measure=String
Group=measuretask6group

[MeasureTask6State]
Measure=String
Group=measuretask6group

[MeasureTask6IconPath]
Measure=String
Group=measuretask6group


;============================================= Task 7 Measures ================================================


[MeasureTask7Exe]
Measure=String
Group=measuretask7group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task7Group]
IfMatchAction=[!HideMeterGroup Task7Group]

[MeasureTask7WindowTitle]
Measure=String
Group=measuretask7group

[MeasureTask7Color]
Measure=String
Group=measuretask7group

[MeasureTask7State]
Measure=String
Group=measuretask7group

[MeasureTask7IconPath]
Measure=String
Group=measuretask7group

;============================================= Task 8 Measures ================================================


[MeasureTask8Exe]
Measure=String
Group=measuretask8group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task8Group]
IfMatchAction=[!HideMeterGroup Task8Group]

[MeasureTask8WindowTitle]
Measure=String
Group=measuretask8group

[MeasureTask8Color]
Measure=String
Group=measuretask8group

[MeasureTask8State]
Measure=String
Group=measuretask8group

[MeasureTask8IconPath]
Measure=String
Group=measuretask8group


;============================================= Task 9 Measures ================================================


[MeasureTask9Exe]
Measure=String
Group=measuretask9group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task9Group]
IfMatchAction=[!HideMeterGroup Task9Group]

[MeasureTask9WindowTitle]
Measure=String
Group=measuretask9group

[MeasureTask9Color]
Measure=String
Group=measuretask9group

[MeasureTask9State]
Measure=String
Group=measuretask9group

[MeasureTask9IconPath]
Measure=String
Group=measuretask9group


;============================================= Task 10 Measures ================================================


[MeasureTask10Exe]
Measure=String
Group=measuretask10group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task10Group]
IfMatchAction=[!HideMeterGroup Task10Group]

[MeasureTask10WindowTitle]
Measure=String
Group=measuretask10group

[MeasureTask10Color]
Measure=String
Group=measuretask10group

[MeasureTask10State]
Measure=String
Group=measuretask10group

[MeasureTask10IconPath]
Measure=String
Group=measuretask10group


;============================================= Task 11 Measures ================================================


[MeasureTask11Exe]
Measure=String
Group=measuretask11group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task11Group]
IfMatchAction=[!HideMeterGroup Task11Group]

[MeasureTask11WindowTitle]
Measure=String
Group=measuretask11group

[MeasureTask11Color]
Measure=String
Group=measuretask11group

[MeasureTask11State]
Measure=String
Group=measuretask11group

[MeasureTask11IconPath]
Measure=String
Group=measuretask11group


;============================================= Task 12 Measures ================================================


[MeasureTask12Exe]
Measure=String
Group=measuretask12group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task12Group]
IfMatchAction=[!HideMeterGroup Task12Group]

[MeasureTask12WindowTitle]
Measure=String
Group=measuretask12group

[MeasureTask12Color]
Measure=String
Group=measuretask12group

[MeasureTask12State]
Measure=String
Group=measuretask12group

[MeasureTask12IconPath]
Measure=String
Group=measuretask12group


;============================================= Task 13 Measures ================================================


[MeasureTask13Exe]
Measure=String
Group=measuretask13group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task13Group]
IfMatchAction=[!HideMeterGroup Task13Group]

[MeasureTask13WindowTitle]
Measure=String
Group=measuretask13group

[MeasureTask13Color]
Measure=String
Group=measuretask13group

[MeasureTask13State]
Measure=String
Group=measuretask13group

[MeasureTask13IconPath]
Measure=String
Group=measuretask13group


;============================================= Task 14 Measures ================================================


[MeasureTask14Exe]
Measure=String
Group=measuretask14group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task14Group]
IfMatchAction=[!HideMeterGroup Task14Group]

[MeasureTask14WindowTitle]
Measure=String
Group=measuretask14group

[MeasureTask14Color]
Measure=String
Group=measuretask14group

[MeasureTask14State]
Measure=String
Group=measuretask14group

[MeasureTask14IconPath]
Measure=String
Group=measuretask14group


;============================================= Task 15 Measures ================================================


[MeasureTask15Exe]
Measure=String
Group=measuretask15group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task15Group]
IfMatchAction=[!HideMeterGroup Task15Group]

[MeasureTask15WindowTitle]
Measure=String
Group=measuretask15group

[MeasureTask15Color]
Measure=String
Group=measuretask15group

[MeasureTask15State]
Measure=String
Group=measuretask15group

[MeasureTask15IconPath]
Measure=String
Group=measuretask15group


;============================================= Task 16 Measures ================================================


[MeasureTask16Exe]
Measure=String
Group=measuretask16group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup Task16Group]
IfMatchAction=[!HideMeterGroup Task16Group]

[MeasureTask16WindowTitle]
Measure=String
Group=measuretask16group

[MeasureTask16Color]
Measure=String
Group=measuretask16group

[MeasureTask16State]
Measure=String
Group=measuretask16group

[MeasureTask16IconPath]
Measure=String
Group=measuretask16group


;============================================= Task Mouse Actions =============================================

[Task1.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 1 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 1 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 1 2"]

[Task2.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 2 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 2 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 2 2"]

[Task3.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 3 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 3 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 3 2"]

[Task4.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 4 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 4 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 4 2"]

[Task5.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 5 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 5 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 5 2"]

[Task6.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 6 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 6 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 6 2"]

[Task7.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 7 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 7 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 7 2"]

[Task8.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 8 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 8 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 8 2"]

[Task9.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 9 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 9 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 9 2"]

[Task10.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 10 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 10 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 10 2"]

[Task11.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 11 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 11 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 11 2"]

[Task12.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 12 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 12 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 12 2"]

[Task13.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 13 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 13 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 13 2"]

[Task14.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 14 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 14 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 14 2"]

[Task15.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 15 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 15 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 15 2"]

[Task16.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 16 0"]
MiddleMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 16 1"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16666 16 2"]


;============================================= Tray 1 Measures ================================================


[MeasureTray1Exe]
Measure=String
Group=measuretray1group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray1group]
IfMatchAction=[!HideMeterGroup tray1group]

[MeasureTray1Title]
Measure=String
Group=measuretray1group

[MeasureTray1Tooltip]
Measure=String
Group=measuretray1group

[MeasureTray1IconPath]
Measure=String
Group=measuretray1group

[MeasureTray1Color]
Measure=String
Group=measuretray1group



;============================================= Tray 2 Measures ================================================


[MeasureTray2Exe]
Measure=String
Group=measuretray2group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray2group]
IfMatchAction=[!HideMeterGroup tray2group]

[MeasureTray2Title]
Measure=String
Group=measuretray2group

[MeasureTray2Tooltip]
Measure=String
Group=measuretray2group

[MeasureTray2IconPath]
Measure=String
Group=measuretray2group

[MeasureTray2Color]
Measure=String
Group=measuretray2group


;============================================= Tray 3 Measures ================================================


[MeasureTray3Exe]
Measure=String
Group=measuretray3group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray3group]
IfMatchAction=[!HideMeterGroup tray3group]

[MeasureTray3Title]
Measure=String
Group=measuretray3group

[MeasureTray3Tooltip]
Measure=String
Group=measuretray3group

[MeasureTray3IconPath]
Measure=String
Group=measuretray3group

[MeasureTray3Color]
Measure=String
Group=measuretray3group


;============================================= Tray 4 Measures ================================================


[MeasureTray4Exe]
Measure=String
Group=measuretray4group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray4group]
IfMatchAction=[!HideMeterGroup tray4group]

[MeasureTray4Title]
Measure=String
Group=measuretray4group

[MeasureTray4Tooltip]
Measure=String
Group=measuretray4group

[MeasureTray4IconPath]
Measure=String
Group=measuretray4group

[MeasureTray4Color]
Measure=String
Group=measuretray4group


;============================================= Tray 5 Measures ================================================


[MeasureTray5Exe]
Measure=String
Group=measuretray5group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray5group]
IfMatchAction=[!HideMeterGroup tray5group]

[MeasureTray5Title]
Measure=String
Group=measuretray5group

[MeasureTray5Tooltip]
Measure=String
Group=measuretray5group

[MeasureTray5IconPath]
Measure=String
Group=measuretray5group

[MeasureTray5Color]
Measure=String
Group=measuretray5group


;============================================= Tray 6 Measures ================================================


[MeasureTray6Exe]
Measure=String
Group=measuretray6group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray6group]
IfMatchAction=[!HideMeterGroup tray6group]

[MeasureTray6Title]
Measure=String
Group=measuretray6group

[MeasureTray6Tooltip]
Measure=String
Group=measuretray6group

[MeasureTray6IconPath]
Measure=String
Group=measuretray6group

[MeasureTray6Color]
Measure=String
Group=measuretray6group


;============================================= Tray 7 Measures ================================================


[MeasureTray7Exe]
Measure=String
Group=measuretray7group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray7group]
IfMatchAction=[!HideMeterGroup tray7group]

[MeasureTray7Title]
Measure=String
Group=measuretray7group

[MeasureTray7Tooltip]
Measure=String
Group=measuretray7group

[MeasureTray7IconPath]
Measure=String
Group=measuretray7group

[MeasureTray7Color]
Measure=String
Group=measuretray7group


;============================================= Tray 8 Measures ================================================


[MeasureTray8Exe]
Measure=String
Group=measuretray8group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray8group]
IfMatchAction=[!HideMeterGroup tray8group]

[MeasureTray8Title]
Measure=String
Group=measuretray8group

[MeasureTray8Tooltip]
Measure=String
Group=measuretray8group

[MeasureTray8IconPath]
Measure=String
Group=measuretray8group

[MeasureTray8Color]
Measure=String
Group=measuretray8group


;============================================= Tray 9 Measures ================================================


[MeasureTray9Exe]
Measure=String
Group=measuretray9group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray9group]
IfMatchAction=[!HideMeterGroup tray9group]

[MeasureTray9Title]
Measure=String
Group=measuretray9group

[MeasureTray9Tooltip]
Measure=String
Group=measuretray9group

[MeasureTray9IconPath]
Measure=String
Group=measuretray9group

[MeasureTray9Color]
Measure=String
Group=measuretray9group


;============================================= Tray 10 Measures ================================================


[MeasureTray10Exe]
Measure=String
Group=measuretray10group
Substitute="":"NULL"
IfMatch = "NULL"
IfNotMatchAction=[!ShowMeterGroup tray10group]
IfMatchAction=[!HideMeterGroup tray10group]

[MeasureTray10Title]
Measure=String
Group=measuretray10group

[MeasureTray10Tooltip]
Measure=String
Group=measuretray10group

[MeasureTray10IconPath]
Measure=String
Group=measuretray10group

[MeasureTray10Color]
Measure=String
Group=measuretray10group