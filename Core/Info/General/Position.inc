[Title]
Text=Position

[Description]
Text=Configure the position of IdleStyle.

[Description2]
Meter=String
Text="Screen to display on - the index of the screen to display the main section of IdleStyle"
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description3]
Meter=String
Text="Amount of screens - the amount of screens that you want IdleStyle to cover. The maximum amount currently supported is 2. If you only want it to cover your primary monitor, set this value to 0."
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description4]
Meter=String
Text="Please note that the skin is unable to do the reverse, that is to have IdleStyle display on the 2nd monitor and cover the 1st. Make sure the values entered are correct to prevent unintentional behaviors."
X=r
Y=(#sec.P#)R
FontColor=255, 183, 0
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S