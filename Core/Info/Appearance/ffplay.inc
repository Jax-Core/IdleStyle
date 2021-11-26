[Title]
Text=ffplay file availability 

[Description]
Text=You'll have to manually download ffplay from the link below in order for this style to function.

[Link]
Meter=String
Text=https://github.com/BtbN/FFmpeg-Builds/releases/download/autobuild-2021-11-19-12-21/ffmpeg-n4.4.1-2-gcc33e73618-win64-lgpl-4.4.zip
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Link:Link"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Link:NoLink"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MeterStyle=Sec.String:S | Link:NoLink
LeftMouseUpAction=["https://github.com/BtbN/FFmpeg-Builds/releases/download/autobuild-2021-11-19-12-21/ffmpeg-n4.4.1-2-gcc33e73618-win64-lgpl-4.4.zip"]
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
[Link:NoLink]
InlinePattern=https://.*
InlineSetting=Color | 88, 166, 218
[Link:Link]
InlinePattern=https://.*
InlineSetting=Underline
InlinePattern2=https://.*
InlineSetting2=Color | 31, 69, 174

[Des2]
Meter=String
Text=After download, uncompress the file and navigate to the bin folder. Copy ffplay.exe and paste it to this folder.
MeterStyle=Sec.String:S | Folder:NoLink
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Folder:Link"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Folder:NoLink"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#SKINSPATH#..\CoreData\IdleStyle"]
[Folder:NoLink]
InlinePattern=this folder
InlineSetting=Color | 88, 166, 218
[Folder:Link]
InlinePattern=this folder
InlineSetting=Underline
InlinePattern2=this folder
InlineSetting2=Color | 31, 69, 174

[Des3]
Meter=String
Text=Refresh the core page and it should show as available after that. You can now add your own videos into IdleStyle and have it display then!
MeterStyle=Sec.String:S | Folder:NoLink
X=r
Y=(#sec.P#)R
FontSize=(12*#Sec.S#)