$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

function Update {
    Check-ffplay
}

function Check-ffplay {
    If (Test-Path -Path "$SkinsPath..\CoreData\IdleStyle\ffplay.exe") {
        $RmAPI.Bang('[!SetOption Item2.StringIcon Text "[\xe73e]"][!SetOption Item2.String Text "Requirements met!"][!SetOptionGroup Ava FontColor "255,0,0"][!SetOptionGroup Ava FontWeight "600"][!SetOptionGroup Ava FontSize "(14*[Set.S])"][!UpdateMeterGroup Ava][!Redraw]')
    } else {
        $RmAPI.Bang('[!SetOption Item2.StringIcon Text "[\xe711]"][!SetOption Item2.String Text "Requirements not met!"][!SetOptionGroup Ava FontColor "255,0,0"][!SetOptionGroup Ava FontWeight "600"][!SetOptionGroup Ava FontSize "(14*[Set.S])"][!UpdateMeterGroup Ava][!Redraw]')
    }
}