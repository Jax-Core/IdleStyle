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
    _, t = SKIN:GetVariable('SkinRow'):gsub("|", "|")
    t = t + 1
    Group = SKIN:GetVariable('Group')
    SkinRow = SKIN:GetVariable('SkinRow')
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