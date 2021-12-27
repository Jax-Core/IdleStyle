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
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\ExtenderDisplay"][!DeactivateConfig]
Start=[!ZPos 1][!ActivateConfig "IdleStyle\Launch\Addons\JDWS" "Annen.ini"]
End=[!Zpos 2][!DeactivateConfig "IdleStyle\Launch\Addons\JDWS" "Annen.ini"]
[mPreview]
ActionList2=Start | Wait 3000 | End | Deactivate
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\ExtenderDisplay"][!DeactivateConfig]
Start=[!ZPos 1][!ActivateConfig "IdleStyle\Launch\Addons\JDWS" "Annen.ini"]
End=[!Zpos 2][!DeactivateConfig "IdleStyle\Launch\Addons\JDWS" "Annen.ini"]