function CheckPause()
    local FullMeasure = SKIN:GetMeasure('MeasureIsFullScreen')
    local mString = FullMeasure:GetStringValue()
    local mNum = FullMeasure:GetValue()

    if mString:match('Rainmeter%.exe') then
        mBool = 1
    else
        mBool = 0
    end

    if tonumber(SKIN:GetVariable('YoutubeCheck')) == 1 then
        if SKIN:GetMeasure('Youtubecheck'):GetStringValue():match('Youtube') then
            yBool = 1
        else
            yBool = 0
        end
    end

    local check = (mNum .. mBool .. yBool)
    if string.match(check, '10.') or string.match(check, '..1') then
        SKIN:Bang('!DisableMeasure', 'IdleTime')
    else
        SKIN:Bang('!EnableMEasure', 'IdleTime')
    end
end

function Update()
    local TimeOutRequirement = parseDuration(SKIN:GetVariable('TimeOut'))
    if enabled == nil then enabled = 0 end
    if TimeOutRequirement <= SKIN:GetMeasure('Idletime'):GetValue() and enabled == 0 and SKIN:GetMeasure('mToggle'):GetValue() == 1 then
        SKIN:Bang('!ActivateConfig', 'IdleStyle\\Launch', 'Main.ini')
        enabled = 1
    elseif TimeOutRequirement > SKIN:GetMeasure('Idletime'):GetValue() and enabled == 1 then
        enabled = 0
    end
end

function disp_time(time)
    local days = floor(time/86400)
    local hours = floor(mod(time, 86400)/3600)
    local minutes = floor(mod(time,3600)/60)
    local seconds = floor(mod(time,60))
    return format("%d:%02d:%02d:%02d",days,hours,minutes,seconds)
end

function parseDuration(input)
    local count, unit = input:match "^(%d+)(%a+)$"
    if not count then
        return nil, "invalid duration `" .. input .. "`"
    end
    local SECONDS_PER = {
        s = 1,
        m = 60,
        h = 60 * 60,
        d = 24 * 60 * 60,
        w = 7 * 24 * 60 * 60,
        -- etc
    }

    if not SECONDS_PER[unit] then
        return nil, "unknown unit `" .. unit .. "`"
    end

    return tonumber(count) * SECONDS_PER[unit]
end