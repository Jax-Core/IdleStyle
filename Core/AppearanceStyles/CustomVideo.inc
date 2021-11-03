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
Command1=[!WriteKeyvalue Variables VideoPath "$Path$" "#Sec.SaveLocatioN#"][!WriteKeyvalue Variables Videoname "$Name$" "#Sec.SaveLocatioN#"][!Refresh]

[HotkeysT2itle]
Meter=String
Text=Customization
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Video path
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Loop video
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s12331138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Video sound
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
Text=#VideoName#
MeterStyle=Set.String:S | Set.Value:S

[Loop]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])
Shape2=Ellipse ([##CURRENTSECTION#] = 0 ? (40*[Set.S]) : (10*[Set.S])),(10*[Set.S]),(6*[Set.S]) | StrokeWidth 0 | Fill Color #Set.Text_Color#
Fill=Fill Color ([##CURRENTSECTION#] = 0 ? 35 : 181),([##CURRENTSECTION#] = 0 ? 209 : 181),([##CURRENTSECTION#] = 0 ? 96 : 181)

[Sound]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])