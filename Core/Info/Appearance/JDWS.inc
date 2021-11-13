[Title]
Text=Jelle's weather skin's configuration

[Description]
Text=This awesome skin is made by Jelle Dekkers!#CRLF#Check him out here: https://
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Des:Link"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[""]
[Des:Link]
InlinePattern=https://
InlineSetting=Underline
InlinePattern2=https://
InlineSetting2=Color | 31, 69, 174