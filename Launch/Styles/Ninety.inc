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
Custom0=
[mPreview]
ActionList2=Start0 | Wait 2000 | Deactivate

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
Shape=Path left | Fill Color #Color1# | StrokeWidth 1 | Stroke Color #Color1#
Shape2=Path Right | Fill Color #Color2# | StrokeWidth 1 | Stroke Color #Color2#
Left=([#SCREENAREAWIDTH@#Location#]*(1-#TweenNode1#)),0 | LineTo ([#SCREENAREAWIDTH@#Location#]*(1-#TweenNode1#)),(-1*([#SCREENAREAHEIGHT@#Location#]/[#SCREENAREAWIDTH@#Location#]*([#SCREENAREAWIDTH@#Location#]*(1-#TweenNode1#))-[#SCREENAREAHEIGHT@#Location#])+#Dis#) | LineTo ([#SCREENAREAWIDTH@#Location#]),#Dis# | LineTo ([#SCREENAREAWIDTH@#Location#]),0
Right=0,([#SCREENAREAHEIGHT@#Location#]+#Dis#) | LineTo ([#SCREENAREAWIDTH@#Location#]*(#TweenNode1#)),[#SCREENAREAHEIGHT@#Location#] | LineTo ([#SCREENAREAWIDTH@#Location#]*(#TweenNode1#)),(-1*([#SCREENAREAHEIGHT@#Location#]/[#SCREENAREAWIDTH@#Location#]*([#SCREENAREAWIDTH@#Location#]*(#TweenNode1#))-[#SCREENAREAHEIGHT@#Location#])+#Dis#)
Group=Tweenable
DynamicVariables=1

[TextIcon]
Meter=String
FontFace=Poppins SemiBold
FontColor=#AccentColor#,(255*#TweenNode1#)
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
Text=O
Inlinesetting=Shadow | 0 | 0 | #GlowIntensity# | #AccentColor#,#GlowAlpha#
TransformationMatrix=1;(-[#SCREENAREAHEIGHT@#Location#]/[#SCREENAREAWIDTH@#Location#]);0;1;([#SCREENAREAWIDTH@#Location#]/2);([#SCREENAREAHEIGHT@#Location#]/2+[String:H]/2)
[String]
Meter=String
FontFace=Poppins SemiBold
FontColor=#TextColor#,(255*#TweenNode1#)
AntiAlias=1
StringAlign=Center
UpdateDivider=10
DynamicVariables=1
Group=Tweenable
Inlinesetting=Shadow | 0 | 0 | #GlowIntensity# | #TextColor#,#GlowAlpha#
TransformationMatrix=1;(-[#SCREENAREAHEIGHT@#Location#]/[#SCREENAREAWIDTH@#Location#]);0;1;([#SCREENAREAWIDTH@#Location#]/2);([#SCREENAREAHEIGHT@#Location#]/2-[String:H]/2)
MeterStyle=Style:#LineOneStyle#
[Style:IdleDuration]
FontSize=40
Text=Idle for [&Func:disp_time([&IdleTime:])]
[Style:Time]
FontSize=50
Text=[mTime#gVar.2412#]
[Style:GreetingMessage]
FontSize=30
Text=#TimeString#
[Style:BatteryLevel]
FontSize=50
Text=Power at [MeasureBatteryPercent]%