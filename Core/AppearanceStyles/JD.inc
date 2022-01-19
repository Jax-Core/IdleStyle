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
Text=Blur
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S

[JDWS]
Meter=String
Text=Jelle's weather skin's configuration
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Weather location
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Weather unit
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S
; [Option13]
; Meter=String
; Text=Language
; MeterStyle=Set.String:S | Set.OptionName:S
; [Set.Div:13]
; Meter=Shape
; MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Use 24 Hour time format
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:14]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Flip details layout
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:15]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Icons style
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:16]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text=Skin aligment
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Blur:0]
Meter=String
Text=None
FontColor=([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Blur:1]
Meter=String
Text=Acrylic
FontColor=([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Blur:2]
Meter=String
Text=Standard
FontColor=([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S

[Background]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=#BackgroundOpacity#
MeterStyle=Set.String:S | Set.Pacity:S


[Info:JDWS]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([JDWS:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Info02]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S

[Button11]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!Refresh]
[Icon11]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S
[Value11]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Change global variable
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S

[Button12]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!Refresh]
[Icon12]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S
[Value12]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Change global variable
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S

; [Language]
; Meter=Shape
; MeterStyle=Set.Textbox:S
; Type=Txt
; Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value13]
; Meter=String
; Text=#gVar.Language#
; MeterStyle=Set.String:S | Set.Value:S

[24HTime]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option14:Y]-#Set.P#+(-20/2+8)*[Set.S])

[DetailsFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option15:Y]-#Set.P#+(-20/2+8)*[Set.S])

[IconStyle:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('IconStyle', 'Color')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables IconStyle "Mono" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables IconStyle "Color" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[IconStyle:0]
Meter=String
Text=Mono
FontColor=([&Func:returnBool('IconStyle', 'Color')] = 0 ? 0 : 255),([&Func:returnBool('IconStyle', 'Color')] = 0 ? 0 : 255),([&Func:returnBool('IconStyle', 'Color')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[IconStyle:1]
Meter=String
Text=Color
FontColor=([&Func:returnBool('IconStyle', 'Color')] = 1 ? 0 : 255),([&Func:returnBool('IconStyle', 'Color')] = 1 ? 0 : 255),([&Func:returnBool('IconStyle', 'Color')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[Alignment:]
Meter=Shape
0Act=[!WriteKeyValue Variables Alignment "Left" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Alignment "Center" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Alignment "Right" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Alignment', 'Center')]+[&Func:returnBool('Alignment', 'Right')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Alignment:0]
Meter=String
Text=Left
FontColor=([&Func:returnBool('Alignment', 'Left')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Left')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Left')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Alignment:1]
Meter=String
Text=Center
FontColor=([&Func:returnBool('Alignment', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Center')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Alignment:2]
Meter=String
Text=Right
FontColor=([&Func:returnBool('Alignment', 'Right')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Right')] = 1 ? 0 : 255),([&Func:returnBool('Alignment', 'Right')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R