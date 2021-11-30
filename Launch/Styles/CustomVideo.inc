[Variables]
UpdateRate=1000
@includeConfigurableVariables=#ROOTCONFIGPATH#Launch\Vars\#Style#.inc

[IdleTime]
UpdateDivider=1

; [mTimeH]
; Measure=Time
; Format=%H:%M
; UpdateDivider=1
; [mTimeI]
; Measure=Time
; Format=%I:%M %p
; UpdateDivider=1

[mActions]
ActionList1=StartVideo | Hide
ActionList2=EndVideo | Deactivate
Hide=[!Hide]
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\Extender"][!DeactivateConfig]
StartVideo=["#@#Actions\AHKv1.exe" "#@#Actions\Source code\FadeIn.ahk"]
EndVideo=["#@#Actions\AHKv1.exe" "#@#Actions\Source code\FadeOut.ahk"]
[mPreview]
ActionList2=StartVideo | Wait 5000 | EndVideo | Deactivate
Deactivate=[!DeactivateConfig "IdleStyle\Launch\Addons\Extender"][!DeactivateConfig]
; StartVideo=[!CommandMeasure CommandVideo#Sound# "Run"]["#@#Actions\AHKv1.exe" "#@#Actions\Source code\FadeIn.ahk"]
StartVideo=["#@#Actions\AHKv1.exe" "#@#Actions\Source code\FadeIn.ahk"]
EndVideo=["#@#Actions\AHKv1.exe" "#@#Actions\Source code\FadeOut.ahk"]