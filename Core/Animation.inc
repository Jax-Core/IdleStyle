[Header]
Text=Animation layout
Y=(20*[Set.S]+#Scroll#)

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
OnUpdateAction=[!SetOption #Style# MeterStyle "Select:S | Selected:S"][!UpdateMeter #Style#][!Redraw]

[Select:S]
X=r
Y=(20*[Set.S])R
W=(650*[Set.S])
H=(150*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Animation\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=100
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables Style "#CURRENTSECTION#" "#Sec.SaveLocatioN#"][!UpdateMeasure Auto_Refresh:M][!Refresh]
Rightmouseupaction=[!WriteKeyValue Variables PreviewStyle "#CURRENTSECTION#" "#SKINSPATH##Skin.Name#\Launch\Preview.ini"][!ActivateConfig "IdleStyle\Launch" "Preview.ini"]
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Selected:S]
Fill=Fill Color 255,255,255,255
ImageAlpha=255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

[Option01]
Meter=String
Text=Left click to select, right click to preview the animation.#CRLF#You can configure the animations in the appearance tab
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[CoreUI]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Ninety]
Meter=Image
MeterStyle=Select:S

[JD]
Meter=Image
MeterStyle=Select:S

[Center]
Meter=Image
MeterStyle=Select:S

[CustomGroup]
Meter=Image
MeterStyle=Select:S

[CustomVideo]
Meter=Image
MeterStyle=Select:S

[CustomPaper]
Meter=Image
MeterStyle=Select:S
