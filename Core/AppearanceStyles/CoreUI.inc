
[HotkeysT2itle]
Meter=String
Text=Font options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Use regular font instead of CoreRunic
MeterStyle=Set.String:S | Set.OptionName:S

[Runic]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])