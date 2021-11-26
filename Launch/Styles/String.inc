[Variables]
UpdateRate=0
TweenNode3=0
TweenNode4=0
TimeString=Fetching...
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=10
[mHour]
Measure=Time
Format=%I
UpdateDivider=10
Substitute="01":"ONE","02":"TWO","03":"THREE","04":"FOUR","05":"FIVE","06":"SIX","07":"SEVEN","08":"EIGHT","09":"NINE","10":"TEN","11":"ELEVEN","12":"TWELVE"
[mMinHead]
Measure=time
Format=%M
RegexpSubstitute=1
UpdateDivider=10
Substitute="^0":"ZERO","^2":"TWENTY","^3":"THIRTY","^4":"FORTY","^5":"FIFTY","10":"TEN","11":"ELEVEN","12":"TWELVE","13":"THIRTEEN","14":"FOURTEEN","15":"FIFTEEN","16":"SIXTEEN","17":"SEVENTEEN","18":"EIGHTEEN","19":"NINTEEN","[1234567890]":""
[mMinTail]
Measure=time
Format=%M
UpdateDivider=10
RegexpSubstitute=1
Substitute="0$":"","[02345]1$":"ONE","[02345]2$":"TWO","[02345]3$":"THREE","[02345]4$":"FOUR","[02345]5$":"FIVE","[02345]6$":"SIX","[02345]7$":"SEVEN","[02345]8$":"EIGHT","[02345]9$":"NINE","[1234567890]":""


[mActions]
ActionList1=Start0 | Wait 100 | Start1 | Wait 100 | Start2 | Wait 100 | Start3
Start1=[!CommandMeasure mTween "Start(1)"]
Start2=[!CommandMeasure mTween "Start(2)"]
Start3=[!CommandMeasure mTween "Start(3)"]
ActionList2=Rewind0 | Wait 100 | Rewind1 | Wait 100 | Rewind2 | Wait 100 | Rewind3 | Wait 900 | Deactivate
Rewind1=[!CommandMeasure mTween "Rewind(1)"]
Rewind2=[!CommandMeasure mTween "Rewind(2)"]
Rewind3=[!CommandMeasure mTween "Rewind(3)"]
[mPreview]
ActionList2=Start0 | Wait 100 | Start1 | Wait 100 | Start2 | Wait 100 | Start3 | Wait 2000 | Rewind0 | Wait 100 | Rewind1 | Wait 100 | Rewind2 | Wait 100 | Rewind3 | Wait 900 | Deactivate
Start1=[!CommandMeasure mTween "Start(1)"]
Start2=[!CommandMeasure mTween "Start(2)"]
Start3=[!CommandMeasure mTween "Start(3)"]
Rewind1=[!CommandMeasure mTween "Rewind(1)"]
Rewind2=[!CommandMeasure mTween "Rewind(2)"]
Rewind3=[!CommandMeasure mTween "Rewind(3)"]

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1000
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 1000
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 1000
Tween3=Single | Variable | TweenNode4 | 0 | 1 | 1000
Optional0=Easing InOutSine
Optional1=Easing InOutSine
Optional2=Easing InOutSine
Optional3=Easing InOutSine
UpdateDivider=1

[B]
Meter=Shape
Shape=Rectangle 0,0,([#SCREENAREAWIDTH@#Location#]*#TweenNode1#),([#SCREENAREAHEIGHT@#Location#]/4) | Extend Common
Shape2=Rectangle 0,([#SCREENAREAHEIGHT@#Location#]/4*1),([#SCREENAREAWIDTH@#Location#]*#TweenNode2#),([#SCREENAREAHEIGHT@#Location#]/4) | Extend Common
Shape3=Rectangle 0,([#SCREENAREAHEIGHT@#Location#]/4*2),([#SCREENAREAWIDTH@#Location#]*#TweenNode3#),([#SCREENAREAHEIGHT@#Location#]/4) | Extend Common
Shape4=Rectangle 0,([#SCREENAREAHEIGHT@#Location#]/4*3),([#SCREENAREAWIDTH@#Location#]*#TweenNode4#),([#SCREENAREAHEIGHT@#Location#]/4) | Extend Common
Common=StrokeWidth 0 | Fill Color #BackgroundColor#
Group=Tweenable
DynamicVariables=1
[Image]
MEter=Image
X=0
Y=0
W=([#SCREENAREAWIDTH@#Location#])
H=([#SCREENAREAHEIGHT@#Location#])
PreserveAspectRatio=2
MeterStyle=ImageMask:#ImageMask#
[ImageMask:1]
Container=B
ImageName=#ImagePath#
[ImageMask:0]
Hidden=1
ImageName=
[Dum]
Meter=String
SolidColor=#BackgroundColor#
UpdatteDivider=-1

[Bcon]
Meter=Shape
W=[#SCREENAREAWIDTH@#Location#]
H=[#SCREENAREAHEIGHT@#Location#]
SolidColor=255,255,255,(255*#TweenNode4#)
Group=Tweenable
DynamicVariables=1
[String]
Meter=String
FontSize=(50*#Scale#)
X=(40*#Scale#)
Y=([#SCREENAREAHEIGHT@#Location#]*0.6)
Text=%1 %2 %3
MeasureName=mHour
MeasureName2=mMinHead
Measurename3=mMinTail
container=Bcon
FontColor=#Color1#
AntiAlias=1
UpdateDivider=10
FontFace=#FontFace#
InlinePattern=^(.*)\s.*\s.*$
InlineSetting=Weight | 650
InlinePattern2=^.*\s(.*)\s(.*)$
InlineSetting2=Weight | 200
[Shape]
Meter=Shape
X=(15*#scale#)r
Y=R
Shape=Line 0,0,((200+400*#TweenNode4#)*#scale#),0 | StrokeWidth 2 | stroke Color #Color1#
Shape2=Line (610*#scale#),(-10*#scale#),(620*#scale#),(10*#scale#) | Extend Common
Shape3=Line (620*#scale#),(-10*#scale#),(630*#scale#),(10*#scale#) | Extend Common
Common=StrokeWidth 1 | stroke Color #Color1#,(255*#TweenNode4#)
container=Bcon
Group=Tweenable
DynamicVariables=1
[String2]
Meter=String
FontSize=(20*#Scale#)
X=(-5*#scale#)r
Y=(20*#scale#)R
Text=Idle for: [&Func:disp_time([&IdleTime:])]
DynamicVariables=1
container=Bcon
FontColor=#Color1#
AntiAlias=1
UpdateDivider=10
FontFace=#FontFace#
FontWeight=200