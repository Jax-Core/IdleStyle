$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

function Update {
    Check-ffplay
}

function Check-ffplay {
    If (Test-Path -Path "$SkinsPath..\CoreData\IdleStyle\ffplay.exe") {
        $RmAPI.Bang('[!SetOption Item2.StringIcon Text "[\xe73e]"][!SetOption Item2.String Text "Requirements met!"][!UpdateMeterGroup Ava][!Redraw]')
    } else {
        $RmAPI.Bang('[!SetOption Item2.StringIcon Text "[\xe711]"][!SetOption Item2.String Text "Requirements not met!"][!UpdateMeterGroup Ava][!Redraw]')
    }
}