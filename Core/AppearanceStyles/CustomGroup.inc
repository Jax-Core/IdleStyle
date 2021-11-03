[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
OnUpdateAction=[!Delay 20][!CommandMeasure CheckForDataFolder "Check-Data"]
ScriptFile=#@#Powershell\CheckData.ps1

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
Command1=[!CommandMeasure Script:M "Edit([[$Path$]], '#Editing#')"]

[DefaultStartActions]
Custom2=[!SetOption AnchorSuppli Y [AnchorSuppli:Y]][!UpdateMeter AnchorSuppli]
[ContentContainer]
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,Clamp(#Set.H#-#Set.P#*2-[AnchorSuppli:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,Clamp(#Set.H#-#Set.P#*2-[AnchorSuppli:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]

[Script:M]
Measure=Script
ScriptFile="#SKINSPATH##Skin.name#\Core\Gen.lua"

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

[Sdsds]
Meter=String
Text=List of skins
MeterStyle=Set.String:S | Set.OptionCat:S


; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Sec.Edit:S]
Fill=Fill Color 0,255,50,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!SetVariable Editing "#CURRENTSECTION#"][!UpdateMEasure Choose:M][!CommandMeasure Choose:M "ChooseFile 1"]

[Sec.Delete:S]
Fill=Fill Color 255,0,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!CommandMeasure Script:M "Remove(0, '#CURRENTSECTION#')"]



; ---------------------------------------------------------------------------- ;
;                                   Includes                                   ;
; ---------------------------------------------------------------------------- ;


@includeInclude=#SKINSPATH#..\CoreData\IdleStyle\Include.inc

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

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