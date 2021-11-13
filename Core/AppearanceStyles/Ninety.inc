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
Text=Title string content
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Wall displacement
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s12331138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Wall color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913123123s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Floor color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1911413s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Text color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:131123128]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Accent color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13112311228]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Glow opacity
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:128]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text=Glow intensity
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startDrop([[#SKINSPATH#IdleStyle\Core\AppearanceStyles\DropdownStyles\StringContent.inc]], '#CURRENTSECTION#', 'Ninety', 'LineOneStyle')"]
[Value01]
Meter=String
Text=#LineOneStyle#
MeterStyle=Set.String:S | Set.Value:S

[Dis]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|400
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Dis#
MeterStyle=Set.String:S | Set.Value:S

[Color1]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]
[Color3]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]
[TextColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]

[GlowAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|255
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#GlowAlpha#
MeterStyle=Set.String:S | Set.Value:S

[GlowIntensity]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value08]
Meter=String
Text=#GlowIntensity#
MeterStyle=Set.String:S | Set.Value:S


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R