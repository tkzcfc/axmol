

local function hup(s)
    return string.upper(string.sub(s, 1, 1)) .. string.sub(s, 2)
end

local function up(s, pat)
    local key = s:match(pat)
    if not key then return s end

    -- if key == "inst" then
    --     return s
    -- end

    local indexstart, indexend = s:find(key)
    if indexstart and indexend then
        local s1 = s:sub(1, indexstart - 1)
        local s2 = hup(s:sub(indexstart, indexend))
        local s3 = s:sub(indexend + 1)
        return s1 .. s2 .. s3
    end
    return s
end




local fileName = "./lua_fairygui.cpp"

local function fmtCodes()
    local allGetFuncName = {}
    local lines = {}
    for line in io.lines(fileName) do
        -- line = up(line, "tolua_function%(tolua_S,%s?\"([%w_]+)\"")
        -- line = up(line, "tolua_variable%(tolua_S,%s?\"([%w_]+)\"")
        -- line = up(line, "lua_pushstring%(L,%s?\"([%w_]+)\"")
        line = string.gsub(line, "\t", "    ")
        table.insert(lines, line)

        local getFuncName = string.match(line, "%s+tolua_variable%(tolua_S,%s+\"[%w_]+\",%s+([%w_%d]+),")
        if getFuncName then
            table.insert(allGetFuncName, getFuncName)
        end
    end


    local variable_getters = {}
    local block_begin = false

    for k, line in pairs(lines) do
        if not block_begin then
            for _, getFuncName in pairs(allGetFuncName) do
                if lines[k + 1] and lines[k + 1] == "{" and line:find(getFuncName .. "%(lua_State%* tolua_S%)") then
                    block_begin = true
                    table.insert(variable_getters, {name = getFuncName, lineIndex = {}})
                    break
                end
            end
        end


        if block_begin then
            table.insert(variable_getters[#variable_getters].lineIndex, k)
        end

        if line == "}" then
            block_begin = false
        end
    end

    for k, v in pairs(variable_getters) do
        for _, index in pairs(v.lineIndex) do
            local line = lines[index]

            if string.match(line, "argc%s+=%s+lua_gettop%(tolua_S%)%s*%-%s*1;") then
                local nextLine = lines[index + 1]
                if nextLine then
                    if string.match(nextLine, "^%s+if%s*%(argc%s*==%s*0%)%s*{") then
                        lines[index] = string.gsub(line, "^(%s+)(.+)", "%1//%2")
                        lines[index + 1] = string.gsub(nextLine, "^(%s+)(.+)", "%1if(true){//%2")

                        print(nextLine)
                    elseif string.match(nextLine, "^%s+if%s*%(argc%s*==%s*0%)") then
                        lines[index] = string.gsub(line, "^(%s+)(.+)", "%1//%2")
                        lines[index + 1] = string.gsub(nextLine, "^(%s+)(.+)", "%1if(true)//%2")
                    end
                end
            end
        end
    end

    local fp = io.open("./lua_fairygui.cpp", "wb")
    fp:write(table.concat(lines, "\n"))
    fp:close()
end



local function exportAPI()
    local lines = {}

    local classInfos = {}
    local start = false
    for line in io.lines(fileName) do
        table.insert(lines, line)

        local className = string.match(line, "%s*int%s+lua_register_fairygui_(.-)%(lua_State%*%s+tolua_S%)")

        if className then
            local note = string.match(line, "//(.+)")
            table.insert(classInfos, {name = className, variables = {}, funcs = {}, note = note})
            start = true
        end

        local curClassInfo = classInfos[#classInfos]

        local variable, getter, setter = string.match(line, "^%s*tolua_variable%(%s*tolua_S,%s*\"(.-)\",%s*([%w_%d]+),%s*([%w_%d]+)%s*%);")
        if variable then 
            local note = string.match(line, "//(.+)")
            table.insert(curClassInfo.variables, {
                name = variable,
                getter = getter,
                setter = setter,
                note = note,
                lineIndex = #lines
            })
        end

        local funcName = string.match(line, "^%s*tolua_function%(%s*tolua_S%s*,%s*\"(.-)\"")
        if funcName then
            local note = string.match(line, "//(.+)")
            table.insert(curClassInfo.funcs, {
                name = funcName,
                note = note,
            })
        end

        if line == "}" then
            start = false
        end
    end



    local o = ""
    local function output(s)
        o = o .. s
    end

    for _, class in pairs(classInfos) do

        if class.note then
            class.note = string.gsub(class.note, " ", "")
            output("-- " .. class.note .. "\n")
        end
        output("FairyGUI." .. class.name .. " = \n")
        output("{\n")
        output("    -- variables\n")
        for k, v in pairs(class.variables) do
            output("    " .. v.name .. ",")
            if v.getter == "nullptr" then
                output(" -- set")
            elseif v.setter == "nullptr" then
                output(" -- get")
            else
                output(" -- get/set")
            end

            if v.note then
                v.note = string.gsub(v.note, " ", "")
                output(" (" .. v.note .. ")")
            end

            output("\n")
        end

        output("\n    -- functions\n")
        for k, v in pairs(class.funcs) do
            output("    " .. v.name .. " = function() end,")
            if v.note then
                v.note = string.gsub(v.note, " ", "")
                output("-- (" .. v.note .. ")")
            end
            output("\n")
        end
        output("}\n\n")
    end

    print(o)
end

-- fmtCodes()
exportAPI()
