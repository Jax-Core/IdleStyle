#SingleInstance Force
#NoTrayIcon

IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, OutputVar2, Hotkeys.ini, Variables, Key2
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH

Hotkey,%OutputVar%,PauseIdleStyle
Hotkey,%OutputVar2%,ShowIdleStyle

Name = ValliStart.ahk
DetectHiddenWindows On
SetTitleMatchMode RegEx
IfWinExist, i)%Name%.* ahk_class AutoHotkey
{
    ValliScriptPath = % RegExReplace(a_scriptdir,"IdleStyle.*\\?$")"Vallistart\@Resources\Actions\Source code\Vallistart.ahk"
    ValliAhkPath = % RegExReplace(a_scriptdir,"IdleStyle.*\\?$")"Vallistart\@Resources\Actions\"
    Run, %ValliAhkPath%AHKv1.exe `"%ValliScriptPath%`", %ValliAhkPath%
}
Return

PauseIdleStyle:
    Run "%RainmeterPath% "!UpdateMeasure "mToggle" "IdleStyle\Main" "
Return

ShowIdleStyle:
    Run "%RainmeterPath% "!UpdateMeasure "mForce" "IdleStyle\Main" "
Return