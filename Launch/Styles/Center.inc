[Variables]
UpdateRate=1000
Scale=([#SCREENAREAWIDTH@#Location#]/1920)
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[Dum]
Meter=String
X=0
Y=0
W=[#SCREENAREAWIDTH@#Location#]
H=[#SCREENAREAHEIGHT@#Location#]
SolidColor=#BackgroundColor#,#BackgroundOpacity#
UpdatteDivider=-1

[IdleTime]
UpdateDivider=1


[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#

[mHour]
Measure=Time
Format=%#gVar.2412#
[mMin]
Measure=Time
Format=%M

[String:S]
FontFace=Roboto
FontColor=#FC#
FontSize=(12*#scale#)
AntiAlias=1
SolidColor=0,0,0,1

[mPreview]
ActionList2=Wait 1000 | Deactivate

[Hour]
Meter=String
MeterStyle=String:S
FontSize=(200*#Scale#)
X=([#SCREENAREAWIDTH@#Location#]/2)
Y=(450*#Scale#)
FontWeight=450
StringAlign=CenterCenter
MeasureName=mHour
FontColor=255,255,255
DynamicVariables=1
UpdateDivider=1
[Min]
Meter=String
MeterStyle=String:S
X=r
Y=(210*#Scale#)r
FontSize=(200*#Scale#)
StringAlign=CenterCenter
FontWeight=450
MeasureName=mMIn
DynamicVariables=1
UpdateDivider=1