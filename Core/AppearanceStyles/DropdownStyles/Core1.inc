[Variables]
SaveLocation="#SKINSPATH#IdleStyle\Launch\Vars\CoreUI.inc"
SaveKey=LineOneStyle

[String:S]
Text=#CURRENTSECTION#
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "#CURRENTSECTION#" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!DeactivateConfig]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Time]
Meter=String
Y=(#Sec.P#)
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[IdleDuration]
Meter=String
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[BatteryLevel]
Meter=String
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[GreetingMessage]
Meter=String
MeterStyle=String:S