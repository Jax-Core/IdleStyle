[Title]
Text=Jelle's weather skin's configuration

[Description]
Text=This awesome skin is made by Jelle Dekkers!#CRLF#Check him out here: https://www.deviantart.com/aj-dekkers/art/862701719
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Des:Link"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://www.deviantart.com/aj-dekkers/art/JDWS-02-Jelle-Dekkers-Weather-Skins-02-862701719"]
[Des:Link]
InlinePattern=https://.*
InlineSetting=Underline
InlinePattern2=https://.*
InlineSetting2=Color | 31, 69, 174