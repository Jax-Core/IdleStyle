function Initialize()
    local Style = SKIN:GetVariable('Style')
    if Style == 'CustomGroup' then
        _, t = SKIN:GetVariable('SkinRow'):gsub("|", "|")
        t = t + 1
        Group = SKIN:GetVariable('Group')
        SkinRow = SKIN:GetVariable('SkinRow')
    end
end

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

function moveAndAlign()
    if tonumber(SKIN:GetVariable('SmartOverlayDetection')) == 1 then
        local function set(...)
            local ret = {}
            for _,k in ipairs({...}) do ret[k] = true end
            return ret
        end     
        local Style = SKIN:GetVariable('Style')
        local index = tonumber(SKIN:GetVariable('Location')) -- index is the origin point
        local stretch = tonumber(SKIN:GetVariable('stretch')) -- stretch is an addition value
        local align = tonumber(SKIN:GetVariable('Align')) -- align is a directional value
        local posX = 0
        local posY = 0
        local filW = 0
        local filH = 0

        local init = 0
        -- ------------------------- if style is transparent ------------------------ --
        if set('CustomGroup', 'JD')[Style] then
        end
        -- --------------------------- if style is oquaqe --------------------------- --
        if set('CoreUI', 'String', 'Ninety', 'Center', 'CustomVideo', 'CustomPaper')[Style] then
            init = 1
        end
        posX = SKIN:GetVariable('SCREENAREAX@'..index + align * init)
        local posYarray = {}
        local filHarray = {}
        for i=init,stretch  do
            table.insert(posYarray, SKIN:GetVariable('SCREENAREAY@'..index + align * i))
            filW = filW + SKIN:GetVariable('SCREENAREAWIDTH@'..index + align * i)
            table.insert(filHarray, SKIN:GetVariable('SCREENAREAHEIGHT@'..index + align * i))
        end
        posY = math.max(unpack(posYarray)) 
        filH = math.max(unpack(filHarray)) 
        SKIN:Bang('[!Move 0 0]')
        SKIN:Bang('!SetOption', 'Filler', 'X', posX)
        SKIN:Bang('!SetOption', 'Filler', 'Y', posY)
        SKIN:Bang('!SetOption', 'Filler', 'W', filW)
        SKIN:Bang('!SetOption', 'Filler', 'H', filH)
        SKIN:Bang('!UpdateMeter', 'Filler')
        SKIN:Bang('!Redraw')
    else
        SKIN:Bang('[!Move '..SKIN:GetVariable('WindowX')..' '..SKIN:GetVariable('WindowY')..']')
        SKIN:Bang('!SetOption', 'Filler', 'W', SKIN:GetVariable('WindowW'))
        SKIN:Bang('!SetOption', 'Filler', 'H', SKIN:GetVariable('WindowH'))
        SKIN:Bang('!UpdateMeter', 'Filler')
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