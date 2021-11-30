[Variables]
UpdateRate=1000
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=1

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#

[mActions]
ActionList1=Start
ActionList2=End | Deactivate
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\Extender"][!DeactivateConfig]
Start=[!CommandMeasure Func "activateConfigGroup()"]
End=[!CommandMeasure Func "deactivateConfigGroup()"]
[mPreview]
ActionList2=Start | Wait 1000 | End | Deactivate
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\Extender"][!DeactivateConfig]
Start=[!CommandMeasure Func "activateConfigGroup()"]
End=[!CommandMeasure Func "deactivateConfigGroup()"]