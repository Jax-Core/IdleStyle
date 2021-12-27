[Title]
Text=Position

[Description]
Text=Configure the position of IdleStyle.

[Description2]
Meter=String
Text=Screen to display on - the index of the screen to display the main section of IdleStyle
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description3]
Meter=String
Text=Amount of screens - the amount of screens that you want IdleStyle to cover. If you only want it to cover your primary monitor, set this value to 0.
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description4]
Meter=String
Text=Alignment of screensaver - direction of the stretched screens
X=r
Y=(#sec.P#)R
; FontColor=255, 183, 0
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description5]
Meter=String
Text=EXAMPLES:#CRLF#if you have to monitors and want to have it stretch from right, input '2 1 right'.#CRLF#If you have 2 screens and stretch from left, input '1 1 left'#CRLF#If you just have one monitor, input '1 0 left'
X=r
Y=(#sec.P#)R
FontColor=255, 183, 0
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S