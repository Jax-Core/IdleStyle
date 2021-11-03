#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
numberkeys := 0


IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH

Hotkey,%OutputVar%,Button
Return

Button:
Run "%RainmeterPath% "!UpdateMeasure "mToggle" "IdleStyle\Main" "
Return