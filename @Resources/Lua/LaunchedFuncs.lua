function disp_time(time)
    local hours = math.floor(time % 86400 / 3600)
    local minutes = math.floor(time % 3600 / 60)
    local seconds = math.floor(time % 60)
    if minutes ~= 0 and hours ~= 0 then
        return(hours..'h '..minutes..'m '..seconds..'s')
    elseif minutes~= 0 then
        return(minutes..'m '..seconds..'s')
    else
        return(seconds..'s')
    end
end

function Initialize()
    local Style = SKIN:GetVariable('Style')
    local index = tonumber(SKIN:GetVariable('Location'))
    local stretch = tonumber(SKIN:GetVariable('stretch'))
    if Style == 'CustomGroup' then
        _, t = SKIN:GetVariable('SkinRow'):gsub("|", "|")
        t = t + 1
        Group = SKIN:GetVariable('Group')
        SkinRow = SKIN:GetVariable('SkinRow')
    end
    if Style == 'Center' or Style == 'CustomGroup' or Style == 'JD' then

        local width = 0
        for i=index, (stretch + index) do 
            width = width + SKIN:GetVariable('SCREENAREAWIDTH@'..i)
        end

        SKIN:Bang('!SetOption', 'Dum', 'W', width)
        SKIN:Bang('!UpdateMeter', 'Dum')
        SKIN:Bang('!Redraw')
    end
    if Style == 'CoreUI' then

        local width = 0
        for i=(index+1), (stretch+1) do 
            width = width + SKIN:GetVariable('SCREENAREAWIDTH@'..i)
        end
        SKIN:Bang('!SetOption', 'Dum', 'W', width)
        SKIN:Bang('!SetOption', 'Dum', 'H', SKIN:GetVariable('SCREENAREAHEIGHT@'..(index+1)))
        SKIN:Bang('!SetOption', 'Dum', 'X', SKIN:GetVariable('SCREENAREAX@'..(index+1)))
        SKIN:Bang('!SetOption', 'Dum', 'Y', SKIN:GetVariable('SCREENAREAY@'..(index+1)))
        SKIN:Bang('!UpdateMeter', 'Dum')
        SKIN:Bang('!Redraw')
    end
end

function Separate(str)
    local o = {}
    for m in str:gmatch('[^%s%|%s]+') do
        table.insert(o, m)
    end
    return o
end

function activateConfigGroup()
    SRT = Separate(SkinRow)
    SKIN:Bang('!ZPos', '1')
    for i=1,t do
        local Config = SRT[i]:gsub('\\[^\\]+%.ini$', '')
        local Skin = SRT[i]:gsub(Config..'\\', '')
        SKIN:Bang('!ActivateConfig', Config, Skin)
        SKIN:Bang('!ZPos', '2', Config)
    end
end

function deactivateConfigGroup()
    SRT = Separate(SkinRow)
    SKIN:Bang('!ZPos', '2')
    for i=1,t do
        local Config = SRT[i]:gsub('\\[^\\]+%.ini$', '')
        SKIN:Bang('!DeactivateConfig', Config)
    end
end