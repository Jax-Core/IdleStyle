[Variables]
UpdateRate=0
TimeString=Fetching...
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
[mTime]
Measure=Time
Format=%H
IfCondition=(mTime > 0) && (mTime <= 11)
IfTrueAction=[!SetVariable TimeString "It's currently morning"]
IfCondition2=(mTime > 11) && (mTime <= 17)
IfTrueAction2=[!SetVariable TimeString "It's currently afternoon"]
IfCondition3=(mTime > 17) && (mTime <= 21)
IfTrueAction3=[!SetVariable TimeString "It's currently evening"]
IfCondition4=(mTime > 21) && (mTime <= 24)
IfTrueAction4=[!SetVariable TimeString "It's currently night"]
UpdateDivider=-1
[MeasureBatteryPercent]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
UpdateDivider=20

[mActions]
ActionList3=Spin | Wait 3000 | StartSpin
Spin=[!CommandMeasure mTween "Restart(1)"]
Custom0=[!CommandMeasure mActions "Execute 3"]
StartSpin=[!Delay 50][!CommandMeasure mActions "Execute 3"]
[mPreview]
ActionList2=Start0 | Custom0 | Wait 2000 | Rewind0 | Wait 1500 | Deactivate
Custom0=[!CommandMeasure mTween "Restart(1)"]

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1500
Tween1=Single | Variable | TweenNode2 | 1 | 0 | 2000
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[B]
Meter=Shape
Shape=Path left | StrokeWidth 0 | Fill Color #Color1# | StrokeWidth 1 | Stroke Color #Color1#
Shape2=Path Right | StrokeWidth 0 | Fill Color #Color2# | StrokeWidth 1 | Stroke Color #Color2#
Left=0,0 | LineTo 0,[#SCREENAREAHEIGHT@#Location#] | LineTo ([#SCREENAREAWIDTH@#Location#]*#TweenNode1#),[#SCREENAREAHEIGHT@#Location#] | LineTo 0,0
Right=([#SCREENAREAWIDTH@#Location#]),([#SCREENAREAHEIGHT@#Location#]) | LineTo ([#SCREENAREAWIDTH@#Location#]),0 | LineTo ([#SCREENAREAWIDTH@#Location#]*(1-#TweenNode1#)),0 | LineTo ([#SCREENAREAWIDTH@#Location#]),([#SCREENAREAHEIGHT@#Location#])
Group=Tweenable
DynamicVariables=1
[Dum]
Meter=String
SolidColor=#Color2#
UpdatteDivider=-1

[Image]
MEter=Image
X=([#SCREENAREAWIDTH@#Location#]/2-256*#TweenNode1#/2)
Y=([#SCREENAREAHEIGHT@#Location#]/2-256*#TweenNode1#/2)
W=(256*#TweenNode1#)
H=(256*#TweenNode1#)
DynamicVariables=1
Group=Tweenable
TransformationMatrix=(Cos(Rad(#TweenNode2#*360)));(-Sin(Rad(#TweenNode2#*360)));(Sin(Rad(#TweenNode2#*360)));(Cos(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode2#*360)))
ImageName=#ImagePath#

[String]
Meter=String
FontSize=30
X=([#SCREENAREAWIDTH@#Location#]/2)
Y=10R
FontFace=Poppins SemiBold
FontColor=255,255,255,(255*#TweenNode1#)
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
MeterStyle=Style:#LineOneStyle#
[String2]
Meter=String
FontSize=15
X=([#SCREENAREAWIDTH@#Location#]/2)
Y=10R
FontFace=Poppins
FontColor=255,255,255,(255*#TweenNode1#)
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
MeterStyle=Style:#LineTwoStyle#
[Style:IdleDuration]
Text=Idle for [&Func:disp_time([&IdleTime:])]
[Style:Time]
Text=[mTime#2412#]
[Style:GreetingMessage]
Text=#TimeString#
[Style:BatteryLevel]
Text=Power at [MeasureBatteryPercent]%