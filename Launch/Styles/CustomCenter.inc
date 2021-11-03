[Variables]
UpdateRate=0
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=10

[mTimeH]
Measure=Time
Format=%H:%M
UpdateDivider=10
[mTimeI]
Measure=Time
Format=%I:%M %p
UpdateDivider=10

[mActions]


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
Shape=Rectangle 0,0,#SCREENAREAWIDTH#,#SCREENAREAHEIGHT# | Fill Color #Color1#
Shape2=Ellipse (#SCREENAREAWIDTH#/2),(#SCREENAREAHEIGHT#/2),(#SCREENAREAWIDTH#/2*(1-#TweenNode1#))
Shape3=Combine Shape | XOR Shape2
; Shape=Path left | StrokeWidth 0 | Fill Color 0C0C0C | StrokeWidth 1 | Stroke Color 0C0C0C
; Shape2=Path Right | StrokeWidth 0 | Fill Color 17,17,17 | StrokeWidth 1 | Stroke Color 17,17,17
; Left=0,0 | LineTo 0,#SCREENAREAHEIGHT# | LineTo (#SCREENAREAWIDTH#*#TweenNode1#),#SCREENAREAHEIGHT# | LineTo 0,0
; Right=(#SCREENAREAWIDTH#),(#SCREENAREAHEIGHT#) | LineTo (#SCREENAREAWIDTH#),0 | LineTo (#SCREENAREAWIDTH#*(1-#TweenNode1#)),0 | LineTo (#SCREENAREAWIDTH#),(#SCREENAREAHEIGHT#)
Group=Tweenable
DynamicVariables=1

[Image]
MEter=Image
X=(#SCREENAREAWIDTH#/2-256*#TweenNode1#/2)
Y=(#SCREENAREAHEIGHT#/2-256*#TweenNode1#/2-256*(1-#TweenNode1#))
W=(256*#TweenNode1#)
H=(256*#TweenNode1#)
DynamicVariables=1
Group=Tweenable
ImageName=#ImagePath#

[String]
Meter=String
FontSize=30
X=(#SCREENAREAWIDTH#/2)
Y=10R
FontFace=Poppins
FontColor=255,255,255,(255*#TweenNode1#)
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
InlinePattern=#CRLF#.*
InlineSetting=Size | 10
MeterStyle=Style:#LineOneStyle#
[Style:IdleDuration]
Text=Idle for [&Func:disp_time([&IdleTime:])]
[Style:Time]
Text=[mTime#2412#]