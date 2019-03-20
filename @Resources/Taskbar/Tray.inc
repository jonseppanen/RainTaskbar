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


;============================================= Tray Mouse Actions =============================================

[Tray1.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 1 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 1 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 1 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 1 4"]

[Tray2.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 2 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 2 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 2 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 2 4"]

[Tray3.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 3 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 3 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 3 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 3 4"]

[Tray4.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 4 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 4 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 4 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 4 4"]

[Tray5.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 5 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 5 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 5 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 5 4"]

[Tray6.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 6 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 6 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 6 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 6 4"]

[Tray7.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 7 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 7 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 7 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 7 4"]

[Tray8.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 8 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 8 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 8 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 8 4"]

[Tray9.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 9 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 9 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 9 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 9 4"]

[Tray10.actions]
LeftMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 10 1"]
LeftMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 10 2"]
RightMouseDownAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 10 3"]
RightMouseUpAction=[!CommandMeasure MeasureWindowMessage "SendMessage 16682 10 4"]