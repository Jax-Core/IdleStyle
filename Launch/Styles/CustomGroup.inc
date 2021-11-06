[Variables]
UpdateRate=1000
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[Dum]
Meter=String
X=0
Y=0
H=[#SCREENAREAHEIGHT@#Location#]
SolidColor=#BackgroundColor#,#BackgroundOpacity#
UpdatteDivider=-1

[IdleTime]
UpdateDivider=1

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#

[mActions]
ActionList1=Start
ActionList2=End | Deactivate
Deactivate=[!DeactivateConfig]
Start=[!CommandMeasure Func "activateConfigGroup()"]
End=[!CommandMeasure Func "deactivateConfigGroup()"]
[mPreview]
ActionList2=Start | Wait 1000 | End | Deactivate
Deactivate=[!DeactivateConfig]
Start=[!CommandMeasure Func "activateConfigGroup()"]
End=[!CommandMeasure Func "deactivateConfigGroup()"]