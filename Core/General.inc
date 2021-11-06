[IdleTiming]
Meter=String
Text=Activation
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Hotkey for pausing IdleStyle
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:38]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Time till the window shows
MeterStyle=Set.String:S | Set.OptionName:S

[Position]
Meter=String
Text=Position
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Screen to display on
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:123123]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Amount of screens to stretch horizontally
MeterStyle=Set.String:S | Set.OptionName:S

[Time]
Meter=String
Text=Time & weather
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option21]
Meter=String
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S | Set.OptionName:S

[Checks]
Meter=String
Text=Idle checks
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option31]
Meter=String
Text=Fullscreen check
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:318]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Youtube player check
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1S1913s138]
Meter=Shape
Hidden=(1-#YoutubeCheck#)
MeterStyle=Set.Div:S
[Option33]
Meter=String
Text=Youtube state check
Hidden=(1-#YoutubeCheck#)
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;
[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
[Value01]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S

[TimeOut]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Time
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#TimeOut#
MeterStyle=Set.String:S | Set.Value:S

[Location]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Int|1|100
[Value11]
Meter=String
Text=#Location#
MeterStyle=Set.String:S | Set.Value:S

[Stretch]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Int|0|2
[Value12]
Meter=String
Text=#Stretch#
MeterStyle=Set.String:S | Set.Value:S

[2412:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('2412', 'H')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables 2412 "I" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables 2412 "H" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[2412:0]
Meter=String
Text=12-Hour
FontColor=([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[2412:1]
Meter=String
Text=24-hour
FontColor=([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[FullScreenCheck]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option31:Y]-#Set.P#+(-20/2+8)*[Set.S])
[YoutubeCheck]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option32:Y]-#Set.P#+(-20/2+8)*[Set.S])
[YoutubeState]
Meter=Shape
MeterStyle=Set.Bool:S
Hidden=(1-#YoutubeCheck#)
Y=([Option33:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Info:IdleTiming]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([IdleTiming:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Info01]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S

[Info:Position]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([Position:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Info02]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S

[Info:Checks]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([Checks:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Info03]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini