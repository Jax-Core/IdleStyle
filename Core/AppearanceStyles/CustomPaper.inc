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

[DefaultStartActions]
Custom2=[!SetOption AnchorSuppli Y [AnchorSuppli:Y]][!UpdateMeter AnchorSuppli]
[ContentContainer]
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,Clamp(#Set.H#-#Set.P#*2-[AnchorSuppli:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,Clamp(#Set.H#-#Set.P#*2-[AnchorSuppli:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]

[HotkeysT2itle]
Meter=String
Text=Customization
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Wallpaper path
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
Text=Text color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1911413s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Shadow / glow color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:138]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Shadow / glow intensity
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13128]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Text size
MeterStyle=Set.String:S | Set.OptionName:S

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
Act=[!CommandMeasure Func "startDrop([[#SKINSPATH#IdleStyle\Core\AppearanceStyles\DropdownStyles\StringContent.inc]], '#CURRENTSECTION#', 'Custompaper', 'LineOneStyle')"]
[Value02]
Meter=String
Text=#LineOneStyle#
MeterStyle=Set.String:S | Set.Value:S

[Button03]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startDrop([[#SKINSPATH#IdleStyle\Core\AppearanceStyles\DropdownStyles\StringContent.inc]], '#CURRENTSECTION#', 'Custompaper', 'LineTwoStyle')"]
[Value03]
Meter=String
Text=#LineTwoStyle#
MeterStyle=Set.String:S | Set.Value:S


[Color1]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]

[Color2]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#Color2Opacity#
MeterStyle=Set.String:S | Set.Pacity:S

[Color2BlurIntensity]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Int|2|10
[Value06]
Meter=String
Text=#Color2BlurIntensity#
MeterStyle=Set.String:S | Set.Value:S

[FontSize]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|20|50
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#FontSize#
MeterStyle=Set.String:S | Set.Value:S


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R