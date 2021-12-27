SetTitleMatchMode, 3
DetectHiddenWindows, On

IniRead, VidPath, ..\..\Launch\Vars\CustomVideo.inc, Variables, VideoPath
IniRead, LoopBool, ..\..\Launch\Vars\CustomVideo.inc, Variables, Loop
    IniRead, SoundBool, ..\..\Launch\Vars\CustomVideo.inc, Variables, Sound
IniRead, Location, ..\Vars.inc, Variables, Location
SysGet, Mon, Monitor, %Location%
MonitorWidth := MonRight - Monleft
MonitorHeight := MonBottom - MonTop

FadeIn(Window, Speed="1")
{
    DetectHiddenWindows, On
    WinSet, Transparent, 0, %Window%
    WinShow, %Window%
    Loop 15
    {
        Sleep %Speed%
        WinSet, Transparent, % A_Index * 17, %Window%
    }
    Return
}

FadeOut(Window, Speed="1")
{
    WinGet, Trans, Transparent, %Window%
    If Not Trans {
        WinHide, %Window%
        WinSet, Transparent, 0, %Window%
        Return
    }
    Loop 15
    {
        WinSet, Transparent, % 255 - A_Index * 17, %Window%
        Sleep %Speed%
    }
    WinHide, %Window%
    Return
}

If (SoundBool = 1) {
    Run, ..\..\..\..\CoreData\IdleStyle\ffplay "%VidPath%" -left %MonLeft% -top %MonTop% -x %MonitorWidth% -y %MonitorHeight% -loop %LoopBool% -window_title "IdleStyle" -hide_banner,, Hide
    }
else
{
    Run, ..\..\..\..\CoreData\IdleStyle\ffplay "%VidPath%" -left %MonLeft% -top %MonTop% -x %MonitorWidth% -y %MonitorHeight% -loop %LoopBool% -window_title "IdleStyle" -hide_banner -an,, Hide
    }
WinWait, IdleStyle
WinSet, AlwaysOnTop, On, IdleStyle
WinSet, ExStyle, +0x20, IdleStyle
FadeIn(ahk_exe ffplay.exe, 1)
ExitApp