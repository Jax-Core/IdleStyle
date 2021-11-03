[Variables]
UpdateRate=0
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=10

[mActions]
ActionList3=Spin | Wait 3000 | StartSpin
Spin=[!CommandMeasure mTween "Restart(1)"]
Custom0=[!CommandMeasure mActions "Execute 3"]
StartSpin=[!CommandMeasure mActions "Execute 3"]

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1500
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 2000
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[B]
Meter=Shape
Shape=Path left | StrokeWidth 0 | Fill Color 0C0C0C | StrokeWidth 1 | Stroke Color 0C0C0C
Shape2=Path Right | StrokeWidth 0 | Fill Color 17,17,17 | StrokeWidth 1 | Stroke Color 17,17,17
Left=0,0 | LineTo 0,#SCREENAREAHEIGHT# | LineTo (#SCREENAREAWIDTH#*#TweenNode1#),#SCREENAREAHEIGHT# | LineTo 0,0
Right=(#SCREENAREAWIDTH#),(#SCREENAREAHEIGHT#) | LineTo (#SCREENAREAWIDTH#),0 | LineTo (#SCREENAREAWIDTH#*(1-#TweenNode1#)),0 | LineTo (#SCREENAREAWIDTH#),(#SCREENAREAHEIGHT#)
Group=Tweenable
DynamicVariables=1

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-256*#TweenNode1#/2)
Y=(#SCREENAREAHEIGHT#/2-256*#TweenNode1#/2)
W=(256*#TweenNode1#)
H=(256*#TweenNode1#)
DynamicVariables=1
Group=Tweenable
TransformationMatrix=(Cos(Rad(#TweenNode2#*360)));(-Sin(Rad(#TweenNode2#*360)));(Sin(Rad(#TweenNode2#*360)));(Cos(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode2#*360)))
ImageName=#@#Images\Logo256.png

[String]
Meter=String
FontSize=30
X=(#SCREENAREAWIDTH#/2)
Y=10R
FontFace=Poppins
FontColor=255,255,255,(255*#TweenNode1#)
Text=Idle for [&Func:disp_time([&IdleTime:])]#CRLF#Waiting for your return
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
InlinePattern=#CRLF#.*
InlineSetting=Size | 10
MeterStyle=Runic:#Runic#
[Runic:0]
InlinePattern2=#CRLF#.*
InlineSetting2=Face | Runic