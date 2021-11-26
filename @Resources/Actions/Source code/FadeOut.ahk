SetTitleMatchMode, 3
DetectHiddenWindows, On

IniRead, VidPath, ..\..\Launch\Vars\CustomVideo.inc, Variables, VideoPath

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
	WinClose, %Window%
	Return
	ExitApp
}

WinWait, IdleStyle
FadeOut(IdleStyle, 1)
ExitApp