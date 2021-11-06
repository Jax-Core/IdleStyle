[Title]
Text=Idle checks

[Description]
Text=Configure how IdleStyle treats activities.

[Description2]
Meter=String
Text=Fullscreen check - checks if there are any full screen applications to prevent IdleStyle from showing when, for example you're gaming
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description3]
Meter=String
Text=Youtube player check - checks if you are on the youtube website. This requires the WebNowPlaying addon to be installed on your browser
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S

[Description4]
Meter=String
Text=Youtube state check - checks if youtube is playing media. This requires the previous option to be turned on.
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S