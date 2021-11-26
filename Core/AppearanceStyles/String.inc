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
Text=Mask background with image
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Wallpaper path
FontColor=#Set.Text_Color#,(255-150*(1-#ImageMask#))
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s12331138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Section scale
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913123123s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Font Face
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1911413s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Text color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:138]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[ImageMask]
Meter=Shape
MeterStyle=Set.bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 1"]
OverColor=#Set.Accent_Color#,150
LeaveColor=#Set.Accent_Color#,50
Hidden=(1-#ImageMask#)
[Value02]
Meter=String
Text=#ImageName#
Hidden=(1-#ImageMask#)
MeterStyle=Set.String:S | Set.Value:S

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[FontFace]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#FontFace#
MeterStyle=Set.String:S | Set.Value:S

[Color1]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]

[BackgroundColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeftMOuseupAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"]
