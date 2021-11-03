[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
GetIcon=0
ReturnValue=WholePath
FileInitialDirectory=
DynamicVariables=1
Command1=[!WriteKeyvalue Variables ImagePath "$Path$" "#Sec.SaveLocatioN#"][!WriteKeyvalue Variables ImageName "$Name$" "#Sec.SaveLocatioN#"][!Refresh]

[HotkeysT2itle]
Meter=String
Text=Customization
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Icon path (For better performance, 256x images are recommended)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Title string content
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s12331138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Subtitle string content
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913123123s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
; [Set.Div:S1911413s138]
; Meter=Shape
; MeterStyle=Set.Div:S
; [Option05]
; Meter=String
; Text=Color 2
; MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 1"]
OverColor=#Set.Accent_Color#,150
LeaveColor=#Set.Accent_Color#,50
[Value01]
Meter=String
Text=#ImageName#
MeterStyle=Set.String:S | Set.Value:S

[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startDrop([[#SKINSPATH#IdleStyle\Core\AppearanceStyles\DropdownStyles\CustomCenter1.inc]], '#CURRENTSECTION#', 'IdleStyle')"]
[Value02]
Meter=String
Text=#LineOneStyle#
MeterStyle=Set.String:S | Set.Value:S

[Button03]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startDrop([[#SKINSPATH#IdleStyle\Core\AppearanceStyles\DropdownStyles\CustomCenter2.inc]], '#CURRENTSECTION#', 'IdleStyle')"]Act=[!CommandMeasure Func "startDrop()"]
[Value03]
Meter=String
Text=#LineTwoStyle#
MeterStyle=Set.String:S | Set.Value:S


[Color1]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]
; [Color2]
; Meter=Shape
; MeterStyle=Set.Color:S
; Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
; LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]