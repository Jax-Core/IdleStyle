function Initialize()
    _, t = SKIN:GetVariable('SkinRow'):gsub("|", "|")
    saveLocation = SKIN:GetVariable('Sec.SaveLocation')
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    skinroot = SKIN:GetVariable('SKINSPATH')..SKIN:GetVariable('Skin.Name')..'\\'

    if t == 0 and SKIN:GetVariable('SkinRow') == '' then
        -- ------------------ generate if SkinRow variable is blank ----------------- --
        print('Blank canvas. Writing data right now.')
        Add()
    elseif SKIN:GetMeter('Option1') == nil then
        -- ------------------ generate if the include.inc is blank ------------------ --
        print('Include.inc is not genereated. Generating now...')
        Add()
    else
        -- ------------------------ write variables to memory ----------------------- --
        t = t + 1
        local RowString = SKIN:GetVariable('SkinRow')
        SRT = Separate(RowString)
        for i=1,t do
            _G["Config"..i] = SRT[i]
        end
    end
    
    if tonumber(SKIN:GetVariable('Sec.ForceWriteVariables')) == 1 then
        print('Force-Writing')
        local t1 = t
        local t2 = t + 2
        local t3 = t + 3
    
        Write(t1, t2, t3)
        SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ForceWriteVariables', '0', skinroot..'Core\\Appearance.inc')
        SKIN:Bang('!UpdateMeasure', 'Auto_Refresh:M')
        SKIN:Bang('!Refresh')
    end

    local tryGetIndex = SKIN:GetVariable('Sec.Num')
    if tryGetIndex then cacheIndex = tryGetIndex end
end

function Separate(str)
    local o = {}
    for m in str:gmatch('[^%s%|%s]+') do
        table.insert(o, m)
    end
    return o
end

function Edit(path, handler)
    local handler = handler:gsub('^EditButton', '')
    path = path:gsub('.*Rainmeter\\Skins\\', '')
    _G["Config"..handler] = path
    
    local resultString = ''
    for i=1, t do
        if i < t then
            resultString = resultString.._G["Config"..i]..' | '
        else
            resultString = resultString.._G["Config"..i]
        end
    end
    -- print(resultString, handler)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'SkinRow', resultString, saveLocation)

    local t1 = t
    local t2 = t + 2
    local t3 = t + 3

    Write(t1, t2, t3)
    SKIN:Bang('!Refresh')
end

function Add()
    local resultString = ''
    for i=1, (t + 1) do
        if i < (t + 1) then
            resultString = resultString.._G["Config"..i]..' | '
        else
            resultString = resultString..'Select'
            _G["Config"..i] = 'Select'
        end
    end

    SKIN:Bang('!WriteKeyValue', 'Variables', 'SkinRow', resultString, saveLocation)

    local t1 = t + 1
    local t2 = t + 2
    local t3 = t + 3
    Write(t1, t2, t3)
    SKIN:Bang('!Refresh')
end

function Remove(initSelection, startingIndex)
    if toggleDelete == nil then toggleDelete = 0 end
    if initSelection == 1 and toggleDelete == 0 then
        toggleDelete = 1
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xF78A]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.RectButton:S | Sec.Delete:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 255,0,0,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 1 and toggleDelete == 1 then
        toggleDelete = 0
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xE70F]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.RectButton:S | Sec.Edit:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 0,255,50,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 0 then

        startingIndex = startingIndex:gsub('^EditButton', '')
        SRT = Separate(SKIN:GetVariable('SkinRow'))
        local resultString = ''

        for i=1, (startingIndex-1) do
            resultString = resultString.._G["Config"..i]..' | '
        end

        for i=startingIndex, (t-1) do
            if i < (t-1) then
                resultString = resultString.._G["Config"..(i+1)]..' | '
            else
                resultString = resultString.._G["Config"..(i+1)]
            end
        end
        resultString = resultString:gsub('%s%|%s$', '')

        SKIN:Bang('!WriteKeyValue', 'Variables', 'SkinRow', resultString, saveLocation)
        SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ForceWriteVariables', '1', skinroot..'Core\\Appearance.inc')

        local t1 = t - 1
        local t2 = t + 2
        local t3 = t + 3
        Write(t1, t2, t3)
        SKIN:Bang('!Refresh')
    end
end

function Write(t1, t2, t3)
    -- -------------------------------------------------------------------------- --
    --                               Write settings                               --
    -- -------------------------------------------------------------------------- --
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'..\\CoreData\\IdleStyle\\Include.inc','w')
    for i=1,t1 do
        File:write(
            '[Option'..i..']\n'
            ,'Meter=String\n'
            ,'Text='.._G["Config"..i]..'\n'
            ,'MeterStyle=Set.String:S | Set.OptionName:S\n'
            ,'[Set.Div:'..i..']\n'
            ,'Meter=Shape\n'
            ,'MeterStyle=Set.Div:S\n'
        )
    end
    File:write(
        '[Option'..t2..']\n'
        ,'Meter=String\n'
        ,'Text=\n'
        ,'MeterStyle=Set.String:S | Set.OptionName:S\n'
    )
    for i=1,t1 do
        File:write(
        '[EditButton'..i..']\n'
        ,'Meter=Shape\n'
        ,'MeterStyle=Set.RectButton:S | Sec.Edit:S\n'
        ,'Y=([Option'..i..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        
        ,'[EditIcon'..i..']\n'
        ,'Meter=String\n'
        ,'FontFace=Segoe MDL2 Assets\n'
        ,'X=(-15*[Set.S])R\n'
        ,'Y=(-15*[Set.S])R\n'
        ,'StringAlign=CenterCenter\n'
        ,'Text=[\\xE70F]\n'
        ,'Group=ActionButton | Actions\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
    )
    end
    File:write(
        '[Button'..t2..']\n'
        ,'Meter=Shape\n'
        ,'MeterStyle=Set.Button:S\n'
        ,'OverColor=0,255,50,150\n'
        ,'LeaveColor=0,255,50,100\n'
        ,'Y=([Option'..t2..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Act=[!CommandMeasure Script:M "Add()"]\n'
        ,'[Value'..t2..']\n'
        ,'Meter=String\n'
        ,'Text=Add an action\n'
        ,'StringAlign=CenterCenter\n'
        ,'X=(150*[Set.S]/2)r\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
    )
    if t1 ~= 1 then
        File:write(
        '[Button'..t3..']\n'
        ,'Meter=Shape\n'
        ,'X=(-235*[Set.S])r\n'
        ,'MeterStyle=Set.Button:S\n'
        ,'OverColor=255,0,50,150\n'
        ,'LeaveColor=255,0,50,100\n'
        ,'Y=([Option'..t2..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Act=[!CommandMeasure Script:M "Remove(1)"]\n'
        ,'[Value'..t3..']\n'
        ,'Meter=String\n'
        ,'Text=Remove...\n'
        ,'StringAlign=CenterCenter\n'
        ,'X=(150*[Set.S]/2)r\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
    )
    end
    File:close()
end