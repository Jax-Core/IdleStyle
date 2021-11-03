[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\Launch\Vars\#Style#.inc
@includeSaveLocation=#SKINSPATH##Skin.Name#\Launch\Vars\#Style#.inc
Sec.ForceWriteVariables=0

[Auto_Refresh:M]
Measure=

[HotkeysTitle]
Meter=String
Text=These settings are linked to the animation theme you've selected.
MeterStyle=Set.String:S | Set.OptionCat:S
[HeaderImage]
Meter=Image
X=r
Y=(10*[Set.S])R
W=([ContentContainer:W]-#Set.P#)
H=(150*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Animation\#Style#.png
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Set.Div:112312311]
Meter=Shape
MeterStyle=Set.Div:S
[Option00]
Meter=String
Text=Preview IdleStyle
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1123123]
Meter=Shape
MeterStyle=Set.Div:S

@includeCoreAppearanceStyles=#SKINSPATH##SKin.Name#\Core\AppearanceStyles\#Style#.inc

[Button00]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=26, 158, 72
LeaveColor=17, 107, 48
Act=[!WriteKeyValue Variables PreviewStyle "#Style#" "#SKINSPATH##Skin.Name#\Launch\Preview.ini"][!ActivateConfig "IdleStyle\Launch" "Preview.ini"]
[Value00]
Meter=String
Text=Activate
MeterStyle=Set.String:S | Set.Value:S
