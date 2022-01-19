forced = 0
forcedTime = 0

function CheckPause()
    -- ------------------------ if checking youtube is on ----------------------- --
    if tonumber(SKIN:GetVariable('YoutubeCheck')) == 1 then
        -- -------------------- if media playing is from youtube -------------------- --
        if SKIN:GetMeasure('Youtubecheck'):GetStringValue():match('Youtube') then
            -- --------------------- if checking youtube pause is on -------------------- --
            if tonumber(SKIN:GetVariable('YoutubeStatus')) == 1 then
                if SKIN:GetMeasure('YoutubeStatus'):GetValue() == '1' then
                    yBool = 1
                else
                    yBool = 0
                end
            -- ----------------- if checking youtube pause is off, pass ----------------- --
            else
                yBool = 1
            end
            -- ------------------- if the media playing isn't youtube ------------------- --
        else
            yBool = 0
        end
    end

    if tonumber(SKIN:GetVariable('FullScreenCheck')) == 1 then 
        FullMeasure = SKIN:GetMeasure('MeasureIsFullScreen')
        mString = FullMeasure:GetStringValue()
        mNum = FullMeasure:GetValue()
        if mString:match('Rainmeter%.exe') or mString:match('Explorer%.EXE') then
            mBool = 1
        else
            mBool = 0
        end
    else
        mNum = 0
        mBool = 0
    end
    
    local check = (mNum .. mBool .. yBool)
    if string.match(check, '10.') or string.match(check, '..1') then
        SKIN:Bang('!DisableMeasure', 'IdleTime')
    else
        SKIN:Bang('!EnableMEasure', 'IdleTime')
    end
end

function Update()
    TimeOutRequirement = parseDuration(SKIN:GetVariable('TimeOut'))
    if enabled == nil then enabled = 0 end
    if TimeOutRequirement <= SKIN:GetMeasure('Idletime'):GetValue() and enabled == 0 and SKIN:GetMeasure('mToggle'):GetValue() == 1 then
        SKIN:Bang('!ActivateConfig', 'IdleStyle\\Launch', 'Main.ini')
        SKIN:Bang('[!CommandMeasure Esc Start]')
        enabled = 1
    elseif TimeOutRequirement > SKIN:GetMeasure('Idletime'):GetValue() and enabled == 1 and forced == 0 then
        enabled = 0
        SKIN:Bang('!CommandMeasure', 'mActions', 'Execute 2', 'IdleStyle\\Launch', 'Main.ini')
        SKIN:Bang('[!CommandMeasure Esc Stop]')
    end
    if forced == 1 then
        forcedTime = forcedTime + 1
        if forcedTime > TimeOutRequirement then
            forced = 0
            forcedTime = 0
        end
        if forcedTime > 3 and SKIN:GetMeasure('Idletime'):GetValue() == 0 then
            forced = 0
            forcedTime = 0
            enabled = 0
            SKIN:Bang('!CommandMeasure', 'mActions', 'Execute 2', 'IdleStyle\\Launch', 'Main.ini')
            SKIN:Bang('[!CommandMeasure Esc Stop]')
        end
    end
    -- print('ForcedTime:'..forcedTime..' | Enabled:'..enabled..' | Forced?'..forced..' | IdleTime'..SKIN:GetMeasure('Idletime'):GetValue()..' | TimeOutRequirement:'..TimeOutRequirement)
end

function EndIdle()
    forced = 0
    forcedTime = 0
    enabled = 0
    SKIN:Bang('!CommandMeasure', 'mActions', 'Execute 2', 'IdleStyle\\Launch', 'Main.ini')
    SKIN:Bang('[!CommandMeasure Esc Stop]')
end


function Force()
    forced = 1
    enabled = 1
    SKIN:Bang('!ActivateConfig', 'IdleStyle\\Launch', 'Main.ini')
    SKIN:Bang('[!CommandMeasure Esc Start]')
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