[Variables]
UpdateRate=1000
TimeString=Fetching...
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=1

[mTimeH]
Measure=Time
Format=%H:%M
UpdateDivider=1
[mTimeI]
Measure=Time
Format=%I:%M %p
UpdateDivider=1
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
UpdateDivider=2

[mActions]
Custom0=
[mPreview]
ActionList2=Wait 1500 | Deactivate

[Image]
MEter=Image
X=0
Y=0
W=([#SCREENAREAWIDTH@#Location#])
H=([#SCREENAREAHEIGHT@#Location#])
PreserveAspectRatio=2
ImageName=#ImagePath#

[String]
Meter=String
FontSize=(#FontSize#)
X=([#SCREENAREAWIDTH@#Location#]/2)
Y=([#SCREENAREAHEIGHT@#Location#]/2)
FontFace=Poppins SemiBold
FontColor=#Color1#
AntiAlias=1
StringAlign=CenterCenter
UpdateDivider=1
DynamicVariables=1
Inlinesetting=Shadow | 0 | 0 | #Color2BlurIntensity# | #Color2Color#,#Color2Opacity#
MeterStyle=Style:#LineOneStyle#
[String2]
Meter=String
FontSize=(#FontSize#/2)
X=([#SCREENAREAWIDTH@#Location#]/2)
Y=10R
FontFace=Poppins
FontColor=#Color1#
Inlinesetting=Shadow | 0 | 0 | #Color2BlurIntensity# | #Color2Color#,#Color2Opacity#
AntiAlias=1
StringAlign=Center
UpdateDivider=1
DynamicVariables=1
MeterStyle=Style:#LineTwoStyle#
[Style:IdleDuration]
Text=Idle for [&Func:disp_time([&IdleTime:])]
[Style:Time]
Text=[mTime#gVar.2412#]
[Style:GreetingMessage]
Text=#TimeString#
[Style:BatteryLevel]
Text=Power at [MeasureBatteryPercent]%