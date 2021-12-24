local savedW = 0
local savedH = 0
local savedX = 0
local savedY = 0

local Resizing = false
local ResizeBorder = nil
local offsetX = 0
local offsetY = 0

function round(num, numDecimalPlaces)
	local mult = 10^(numDecimalPlaces or 0)
	return math.floor(num * mult + 0.5) / mult
  end

function MouseMovedCallback(mouseX, mouseY)
	if not Resizing then 
		print("Error, MouseMovedCallback called when not resizing")
		return
	end

	local skinPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
	local skinPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
	local windowWidth = tonumber(SKIN:GetVariable("WindowW"))
	local windowHeight = tonumber(SKIN:GetVariable("WindowH"))
	local minWindowWidth = tonumber(SKIN:GetVariable("MinWindowW"))
	local minWindowHeight = tonumber(SKIN:GetVariable("MinWindowH"))
	-- local dragMargin = tonumber(SKIN:GetVariable("WindowDragMarginSize"))
	local dragMargin = 0

	local newWindowX = nil
	local newWindowY = nil
	local newWindowWidth = nil
	local newWindowHeight = nil

	if ResizeBorder == "DragMarginRight" or ResizeBorder == "DragMarginTopRight" or ResizeBorder == "DragMarginBottomRight" then
		newWindowWidth = (mouseX - skinPosX - dragMargin - offsetX)
	end

	if ResizeBorder == "DragMarginBottom" or ResizeBorder == "DragMarginBottomRight" or ResizeBorder == "DragMarginBottomLeft" then
		newWindowHeight = (mouseY - skinPosY - dragMargin - offsetY)
	end

	if ResizeBorder == "DragMarginLeft" or ResizeBorder == "DragMarginBottomLeft" or ResizeBorder == "DragMarginTopLeft" then
		newWindowX = mouseX - offsetX
		newWindowWidth = windowWidth + skinPosX - newWindowX 
	end

	if ResizeBorder == "DragMarginTop" or ResizeBorder == "DragMarginTopLeft" or ResizeBorder == "DragMarginTopRight" then
		newWindowY = mouseY - offsetY
		newWindowHeight = windowHeight + skinPosY - newWindowY 
	end

	local bang = ""

	if newWindowWidth ~= nil then -- if Width is changed then
		if newWindowX ~= nil then
			if newWindowWidth < minWindowWidth then
				newWindowX = newWindowX - minWindowWidth + newWindowWidth
			end
		end
		-- ------------------- make boundaries with min max check ------------------- --
		if newWindowWidth < minWindowWidth then newWindowWidth = minWindowWidth end
		-- ------------------------- set variable for width ------------------------- --
		bang = bang .. "[!SetVariable WindowW " .. newWindowWidth .. "]" 
	end

	if newWindowHeight ~= nil then -- if Height is changed then
		if newWindowY ~= nil then
			if newWindowHeight < minWindowHeight then
				newWindowY = newWindowY - minWindowHeight + newWindowHeight
			end
		end
		-- ------------------- make boundaries with min max check ------------------- --
		if newWindowHeight < minWindowHeight then newWindowHeight = minWindowHeight end
		-- ------------------------- set variable for height ------------------------- --
		bang = bang .. "[!SetVariable WindowH " .. newWindowHeight .. "]" 
	end
	
	if bang ~= "" then
		--bang = bang .. "[!UpdateMeterGroup Window][!Redraw]" TODO When clip is implemented?
		bang = bang .. "[!UpdateMeter *][!Redraw]"

	end

	if newWindowX ~= nil and newWindowY ~= nil then
		bang = bang .. "[!Move " .. newWindowX .. " " .. newWindowY .. "]"
	elseif newWindowX ~= nil then
		bang = bang .. "[!Move " .. newWindowX .. " " .. skinPosY .. "]"
	elseif newWindowY ~= nil then
		bang = bang .. "[!Move " .. skinPosX .. " " .. newWindowY .. "]"
	end

	SKIN:Bang(bang)	
end

function LeftMouseUpCallback(mouseX, mouseY)
	bang = "[!CommandMeasure ScriptMouseHandler UnsubscribeMouseEvent('WindowHandler','MouseMove')]"
	bang = bang .. "[!CommandMeasure ScriptMouseHandler UnsubscribeMouseEvent('WindowHandler','LeftMouseUp')]"
	local skinPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
	local skinPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
	local windowWidth = tonumber(SKIN:GetVariable("WindowW"))
	local windowHeight = tonumber(SKIN:GetVariable("WindowH"))
	-- bang = bang .. "[!WriteKeyValue Variables WindowX " .. skinPosX .. ' "#@#Vars.inc"]' 							   			-- Write X pos in case of refresh
	-- bang = bang .. "[!WriteKeyValue Variables WindowY " .. skinPosY .. ' "#@#Vars.inc"]' 							   			-- Write Y pos in case of refresh
	-- bang = bang .. "[!WriteKeyValue Variables WindowW " .. windowWidth .. ' "#@#Vars.inc"]' 					   			-- Write Width in case of refresh
	-- bang = bang .. "[!WriteKeyValue Variables WindowH " .. windowHeight .. ' "#@#Vars.inc"]' 					   			-- Write Height in case of refresh
	bang = bang .. "[!UpdateMeter *][!UpdateMeasureGroup Dynamic][!Redraw]"

	SKIN:Bang(bang)
	ResizeBorder = nil
	Resizing = false
end

function ResizeWindow(border, mouseX, mouseY)
	local mouseHandler = SKIN:GetMeasure("ScriptMouseHandler")
	if mouseHandler == nil then
		print("Mouse handler not found, include module ScriptMouseHandler")
		return
	end
	ResizeBorder = border
	Resizing = true
	bang = "[!CommandMeasure ScriptMouseHandler SubscribeMouseEvent('MouseMovedCallback','WindowHandler','MouseMove')]"
	bang = bang .. "[!CommandMeasure ScriptMouseHandler SubscribeMouseEvent('LeftMouseUpCallback','WindowHandler','LeftMouseUp')]"
	SKIN:Bang(bang)
	offsetX = mouseX
	offsetY = mouseY
end

function Initialize()
end