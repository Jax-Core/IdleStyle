#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
numberkeys := 0

IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, OutputVar2, Hotkeys.ini, Variables, Key2
; IniRead, CheckUsingPhysical, ..\Vars.inc, Variables, CheckUsingPhysical
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH

; if (CheckUsingPhysical = 1) {
;     SetTimer, Check, 500
; }

Hotkey,%OutputVar%,PauseIdleStyle
Hotkey,%OutputVar2%,ShowIdleStyle
Return

PauseIdleStyle:
    Run "%RainmeterPath% "!UpdateMeasure "mToggle" "IdleStyle\Main" "
Return

ShowIdleStyle:
    Run "%RainmeterPath% "!UpdateMeasure "mForce" "IdleStyle\Main" "
Return