#include "lua_imguiColorTextEdit_auto.hpp"

#if 0
#include "ImGuiColorTextEdit/TextEditor.h"
#include "imgui_lua.hpp"
#include <array>

int luaReg_imguiTextEditor_imguiTextEditorPaletteIndex(lua_State* lua_S)
{
	LUA_ENUM_DEF("PaletteIndex");
    LUA_ENUM_ENTRY("Default", TextEditor::PaletteIndex::Default);
	LUA_ENUM_ENTRY("Keyword", TextEditor::PaletteIndex::Keyword);
	LUA_ENUM_ENTRY("Number", TextEditor::PaletteIndex::Number);
	LUA_ENUM_ENTRY("String", TextEditor::PaletteIndex::String);
	LUA_ENUM_ENTRY("CharLiteral", TextEditor::PaletteIndex::CharLiteral);
	LUA_ENUM_ENTRY("Punctuation", TextEditor::PaletteIndex::Punctuation);
	LUA_ENUM_ENTRY("Preprocessor", TextEditor::PaletteIndex::Preprocessor);
	LUA_ENUM_ENTRY("Identifier", TextEditor::PaletteIndex::Identifier);
	LUA_ENUM_ENTRY("KnownIdentifier", TextEditor::PaletteIndex::KnownIdentifier);
	LUA_ENUM_ENTRY("PreprocIdentifier", TextEditor::PaletteIndex::PreprocIdentifier);
	LUA_ENUM_ENTRY("Comment", TextEditor::PaletteIndex::Comment);
	LUA_ENUM_ENTRY("MultiLineComment", TextEditor::PaletteIndex::MultiLineComment);
	LUA_ENUM_ENTRY("Background", TextEditor::PaletteIndex::Background);
	LUA_ENUM_ENTRY("Cursor", TextEditor::PaletteIndex::Cursor);
	LUA_ENUM_ENTRY("Selection", TextEditor::PaletteIndex::Selection);
	LUA_ENUM_ENTRY("ErrorMarker", TextEditor::PaletteIndex::ErrorMarker);
	LUA_ENUM_ENTRY("Breakpoint", TextEditor::PaletteIndex::Breakpoint);
	LUA_ENUM_ENTRY("LineNumber", TextEditor::PaletteIndex::LineNumber);
	LUA_ENUM_ENTRY("CurrentLineFill", TextEditor::PaletteIndex::CurrentLineFill);
	LUA_ENUM_ENTRY("CurrentLineFillInactive", TextEditor::PaletteIndex::CurrentLineFillInactive);
	LUA_ENUM_ENTRY("CurrentLineEdge", TextEditor::PaletteIndex::CurrentLineEdge);
	LUA_ENUM_ENTRY("Max", TextEditor::PaletteIndex::Max);
	LUA_ENUM_END();
	return 0;
}
int luaReg_imguiTextEditor_imguiTextEditorSelectionMode(lua_State* lua_S)
{
	LUA_ENUM_DEF("SelectionMode");
    LUA_ENUM_ENTRY("Normal", TextEditor::SelectionMode::Normal);
	LUA_ENUM_ENTRY("Word", TextEditor::SelectionMode::Word);
	LUA_ENUM_ENTRY("Line", TextEditor::SelectionMode::Line);
	LUA_ENUM_END();
	return 0;
}
int lua_ImGui_TextEditor_addLanguageIdentifier(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:addLanguageIdentifier");
    LUA_TRY_INVOKE(1, &TextEditor::AddLanguageIdentifier);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_addLanguagePreprocIdentifier(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:addLanguagePreprocIdentifier");
    LUA_TRY_INVOKE(1, &TextEditor::AddLanguagePreprocIdentifier);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_canRedo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:canRedo");
    LUA_TRY_INVOKE_R(0, &TextEditor::CanRedo);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_canUndo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:canUndo");
    LUA_TRY_INVOKE_R(0, &TextEditor::CanUndo);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_copy(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:copy");
    LUA_TRY_INVOKE(0, &TextEditor::Copy);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_cut(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:cut");
	LUA_TRY_INVOKE(0, &TextEditor::Cut);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_delete(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:delete");
	LUA_TRY_INVOKE(0, &TextEditor::Delete);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getCurrentLineText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getCurrentLineText");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetCurrentLineText);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getCursorPosition(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "imgui.TextEditor", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
    {
        tolua_error(tolua_S, "#ferror in function 'getCursorPosition'.", &tolua_err);
        return 0;
    }
    else
    {
        TextEditor* self = (TextEditor*)tolua_tousertype(tolua_S, 1, 0);
        if (!self)
        {
            tolua_error(tolua_S, "invalid 'self' in function 'getCursorPosition'", NULL);
            return 0;
        }
        else
        {
            tolua_pushnumber(tolua_S, (lua_Number)self->GetCursorPosition().mLine);
            tolua_pushnumber(tolua_S, (lua_Number)self->GetCursorPosition().mColumn);
        }
        return 2;
    }
}
int lua_ImGui_TextEditor_getHoveredCoordinates(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "imgui.TextEditor", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
    {
        tolua_error(tolua_S, "#ferror in function 'getHoveredCoordinates'.", &tolua_err);
        return 0;
    }
    else
    {
        TextEditor* self = (TextEditor*)tolua_tousertype(tolua_S, 1, 0);
        if (!self)
        {
            tolua_error(tolua_S, "invalid 'self' in function 'getHoveredCoordinates'", NULL);
            return 0;
        }
        else
        {
            tolua_pushnumber(tolua_S, (lua_Number)self->GetHoveredCoordinates().mLine);
            tolua_pushnumber(tolua_S, (lua_Number)self->GetHoveredCoordinates().mColumn);
        }
        return 2;
    }
}
int lua_ImGui_TextEditor_getHoveredDeclaration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getHoveredDeclaration");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetHoveredDeclaration);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getHoveredWord(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getHoveredWord");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetHoveredWord);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getHoveredWordIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getHoveredWordIndex");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetHoveredWordIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getPalette(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getPalette");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetPalette);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getSelectedText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getSelectedText");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetSelectedText);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getTabSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getTabSize");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetTabSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getText");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->GetText(); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getTextLines(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getTextLines");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetTextLines);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_getTotalLines(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:getTotalLines");
	LUA_TRY_INVOKE_R(0, &TextEditor::GetTotalLines);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_hasSelection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:hasSelection");
	LUA_TRY_INVOKE_R(0, &TextEditor::HasSelection);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_insertText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:insertText");
    LUA_TRY_INVOKE(1, [](TextEditor* obj, const std::string& text) {{ return obj->InsertText(text); }});
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_isAutoTooltip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isAutoTooltip");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsAutoTooltip);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isColorizerEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isColorizerEnabled");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsColorizerEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isCursorPositionChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isCursorPositionChanged");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsCursorPositionChanged);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isHandleKeyboardInputsEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isHandleKeyboardInputsEnabled");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsHandleKeyboardInputsEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isHandleMouseInputsEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isHandleMouseInputsEnabled");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsHandleMouseInputsEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isImGuiChildIgnored(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isImGuiChildIgnored");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsImGuiChildIgnored);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isOverwrite(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isOverwrite");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsOverwrite);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isReadOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isReadOnly");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsReadOnly);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isShowingShortTabGlyphs(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isShowingShortTabGlyphs");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsShowingShortTabGlyphs);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isShowingWhitespaces(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isShowingWhitespaces");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsShowingWhitespaces);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_isTextChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:isTextChanged");
	LUA_TRY_INVOKE_R(0, &TextEditor::IsTextChanged);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_moveBottom(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveBottom");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(bool)>(&TextEditor::MoveBottom));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveBottom();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_ImGui_TextEditor_moveDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveDown");
	LUA_TRY_INVOKE(2, static_cast<void(TextEditor::*)(int, bool)>(&TextEditor::MoveDown));
	LUA_TRY_INVOKE(1, [](TextEditor* obj,int arg0){{return obj->MoveDown(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveDown();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_ImGui_TextEditor_moveEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveEnd");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(bool)>(&TextEditor::MoveEnd));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveEnd();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_ImGui_TextEditor_moveHome(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveHome");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(bool)>(&TextEditor::MoveHome));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveHome();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_ImGui_TextEditor_moveLeft(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveLeft");
	LUA_TRY_INVOKE(3, static_cast<void(TextEditor::*)(int, bool, bool)>(&TextEditor::MoveLeft));
	LUA_TRY_INVOKE(2, [](TextEditor* obj,int arg0,bool arg1){{return obj->MoveLeft(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](TextEditor* obj,int arg0){{return obj->MoveLeft(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveLeft();}});
	LUA_INVOKE_FOOTER("0,1,2,3");
}
int lua_ImGui_TextEditor_moveRight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveRight");
	LUA_TRY_INVOKE(3, static_cast<void(TextEditor::*)(int, bool, bool)>(&TextEditor::MoveRight));
	LUA_TRY_INVOKE(2, [](TextEditor* obj,int arg0,bool arg1){{return obj->MoveRight(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](TextEditor* obj,int arg0){{return obj->MoveRight(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveRight();}});
	LUA_INVOKE_FOOTER("0,1,2,3");
}
int lua_ImGui_TextEditor_moveTop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveTop");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(bool)>(&TextEditor::MoveTop));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveTop();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_ImGui_TextEditor_moveUp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:moveUp");
	LUA_TRY_INVOKE(2, static_cast<void(TextEditor::*)(int, bool)>(&TextEditor::MoveUp));
	LUA_TRY_INVOKE(1, [](TextEditor* obj,int arg0){{return obj->MoveUp(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->MoveUp();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_ImGui_TextEditor_paste(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:paste");
	LUA_TRY_INVOKE(0, &TextEditor::Paste);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_redo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:redo");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(int)>(&TextEditor::Redo));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->Redo();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_ImGui_TextEditor_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:render");
	LUA_TRY_INVOKE(3, [](TextEditor* obj,const char* arg0,const ax::Vec2& size,bool border){{return obj->Render(arg0, { size.x,size.y }, border);}});
	LUA_TRY_INVOKE(2, [](TextEditor* obj,const char* arg0,const ax::Vec2& size){{return obj->Render(arg0, { size.x,size.y });}});
	LUA_TRY_INVOKE(1, [](TextEditor* obj,const char* arg0){{return obj->Render(arg0);}});
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_ImGui_TextEditor_selectAll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:selectAll");
	LUA_TRY_INVOKE(0, &TextEditor::SelectAll);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_selectWordUnderCursor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:selectWordUnderCursor");
	LUA_TRY_INVOKE(0, &TextEditor::SelectWordUnderCursor);
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setAutoTooltip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setAutoTooltip");
	LUA_TRY_INVOKE(1, &TextEditor::SetAutoTooltip);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setBreakpoints(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setBreakpoints");
	LUA_TRY_INVOKE(1, &TextEditor::SetBreakpoints);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setColorizerEnable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setColorizerEnable");
	LUA_TRY_INVOKE(1, &TextEditor::SetColorizerEnable);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setCursorPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setCursorPosition");
	LUA_TRY_INVOKE(2, [](TextEditor* obj,int line, int column){{return obj->SetCursorPosition({ line, column });}});
	LUA_INVOKE_FOOTER("2");
}
int lua_ImGui_TextEditor_setErrorMarkers(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setErrorMarkers");
	LUA_TRY_INVOKE(1, &TextEditor::SetErrorMarkers);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setHandleKeyboardInputs(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setHandleKeyboardInputs");
	LUA_TRY_INVOKE(1, &TextEditor::SetHandleKeyboardInputs);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setHandleMouseInputs(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setHandleMouseInputs");
	LUA_TRY_INVOKE(1, &TextEditor::SetHandleMouseInputs);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setImGuiChildIgnored(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setImGuiChildIgnored");
	LUA_TRY_INVOKE(1, &TextEditor::SetImGuiChildIgnored);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setLanguageAngelScript(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageAngelScript");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::AngelScript()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setLanguageC(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageC");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::C()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setLanguageCPlusPlus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageCPlusPlus");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::CPlusPlus()); }});
	LUA_INVOKE_FOOTER("0");
}

void lua_ImGui_TextEditor_setLanguageDefinitionImpl(
    TextEditor* e,
    const std::string& name,
    const std::unordered_set<std::string>& keywords,
    const std::unordered_map<std::string, std::string>& identifiers,
    const std::unordered_map<std::string, std::string>& preprocIdentifiers,
    const std::vector<std::pair<std::string, TextEditor::PaletteIndex>>& tokenRegexStrings,
    const std::string& commentStart,
    const std::string& commentEnd,
    const std::string& singleLineComment,
    const std::string& preprocChar = "#",
    bool autoIndentation           = true,
    bool caseSensitive             = true)
{
        TextEditor::LanguageDefinition lang;
        lang.mName     = name;
        lang.mKeywords = keywords;
        TextEditor::Identifiers id;
        for (auto&& it : identifiers)
            id[it.first] = {{}, it.second};
        lang.mIdentifiers = id;
        TextEditor::Identifiers pid;
        for (auto&& it : preprocIdentifiers)
            id[it.first] = {{}, it.second};
        lang.mPreprocIdentifiers = pid;
        TextEditor::LanguageDefinition::TokenRegexStrings tokens;
        for (auto&& it : tokenRegexStrings)
            tokens.emplace_back(it.first, (TextEditor::PaletteIndex)it.second);
        lang.mTokenRegexStrings = tokens;
        lang.mCommentStart      = commentStart;
        lang.mCommentEnd        = commentEnd;
        lang.mSingleLineComment = singleLineComment;
        lang.mPreprocChar       = preprocChar.empty() ? '\0' : preprocChar.at(0);
        lang.mAutoIndentation   = autoIndentation;
        lang.mCaseSensitive     = caseSensitive;
        try
        {
            e->SetLanguageDefinition(lang);
        }
        catch (...)
        {
            lang.mTokenRegexStrings.clear();
            e->SetLanguageDefinition(lang);
            cocos2d::log("invalid regex");
        }
}

int lua_ImGui_TextEditor_setLanguageDefinition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageDefinition");
    LUA_TRY_INVOKE(11, [](TextEditor* obj,const std::string& arg0,const std::unordered_set<std::basic_string<char>>& arg1,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg2,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg3,const std::vector<std::pair<std::basic_string<char>, TextEditor::PaletteIndex>>& arg4,const std::string& arg5,const std::string& arg6,const std::string& arg7,const std::string& arg8,bool arg9, bool arg10){{return lua_ImGui_TextEditor_setLanguageDefinitionImpl(obj,arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9, arg10);}});
	LUA_TRY_INVOKE(10, [](TextEditor* obj,const std::string& arg0,const std::unordered_set<std::basic_string<char>>& arg1,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg2,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg3,const std::vector<std::pair<std::basic_string<char>, TextEditor::PaletteIndex>>& arg4,const std::string& arg5,const std::string& arg6,const std::string& arg7,const std::string& arg8,bool arg9){{return lua_ImGui_TextEditor_setLanguageDefinitionImpl(obj,arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);}});
	LUA_TRY_INVOKE(9, [](TextEditor* obj,const std::string& arg0,const std::unordered_set<std::basic_string<char>>& arg1,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg2,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg3,const std::vector<std::pair<std::basic_string<char>, TextEditor::PaletteIndex>>& arg4,const std::string& arg5,const std::string& arg6,const std::string& arg7,const std::string& arg8){{return lua_ImGui_TextEditor_setLanguageDefinitionImpl(obj,arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);}});
	LUA_TRY_INVOKE(8, [](TextEditor* obj,const std::string& arg0,const std::unordered_set<std::basic_string<char>>& arg1,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg2,const std::unordered_map<std::basic_string<char>, std::basic_string<char>>& arg3,const std::vector<std::pair<std::basic_string<char>, TextEditor::PaletteIndex>>& arg4,const std::string& arg5,const std::string& arg6,const std::string& arg7){{return lua_ImGui_TextEditor_setLanguageDefinitionImpl(obj,arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}});
	LUA_INVOKE_FOOTER("10,11,8,9");
}
int lua_ImGui_TextEditor_setLanguageGLSL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageGLSL");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::GLSL()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setLanguageHLSL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageHLSL");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::HLSL()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setLanguageLua(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageLua");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::Lua()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setLanguageSQL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setLanguageSQL");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetLanguageDefinition(TextEditor::LanguageDefinition::SQL()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setPalette(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setPalette");
	LUA_TRY_INVOKE(1, &TextEditor::SetPalette);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setPaletteDark(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setPaletteDark");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetPalette(TextEditor::GetDarkPalette()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setPaletteLight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setPaletteLight");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetPalette(TextEditor::GetLightPalette()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setPaletteRetroBlue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setPaletteRetroBlue");
    LUA_TRY_INVOKE(0, [](TextEditor* obj) {{ return obj->SetPalette(TextEditor::GetRetroBluePalette()); }});
	LUA_INVOKE_FOOTER("0");
}
int lua_ImGui_TextEditor_setReadOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setReadOnly");
	LUA_TRY_INVOKE(1, &TextEditor::SetReadOnly);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setSelection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setSelection");
	LUA_TRY_INVOKE(4, [](TextEditor* obj,int lineStart,int columnStart,int lineEnd,int columnEnd, int mode){{return obj->SetSelection({ lineStart, columnStart }, { lineEnd, columnEnd }, TextEditor::SelectionMode(mode));}});
	LUA_TRY_INVOKE(4, [](TextEditor* obj,int lineStart,int columnStart,int lineEnd,int columnEnd){{return obj->SetSelection({ lineStart, columnStart }, { lineEnd, columnEnd }, TextEditor::SelectionMode::Normal);}});
	LUA_INVOKE_FOOTER("4,5");
}
int lua_ImGui_TextEditor_setSelectionEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setSelectionEnd");
	LUA_TRY_INVOKE(2, [](TextEditor* obj,int line, int column){{return obj->SetSelectionEnd({ line, column });}});
	LUA_INVOKE_FOOTER("2");
}
int lua_ImGui_TextEditor_setSelectionStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setSelectionStart");
	LUA_TRY_INVOKE(2, [](TextEditor* obj,int line, int column){{return obj->SetSelectionStart({ line, column });}});
	LUA_INVOKE_FOOTER("2");
}
int lua_ImGui_TextEditor_setShowShortTabGlyphs(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setShowShortTabGlyphs");
	LUA_TRY_INVOKE(1, &TextEditor::SetShowShortTabGlyphs);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setShowWhitespaces(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setShowWhitespaces");
	LUA_TRY_INVOKE(1, &TextEditor::SetShowWhitespaces);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setTabSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setTabSize");
	LUA_TRY_INVOKE(1, &TextEditor::SetTabSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setText");
	LUA_TRY_INVOKE(1, &TextEditor::SetText);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_setTextLines(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:setTextLines");
	LUA_TRY_INVOKE(1, &TextEditor::SetTextLines);
	LUA_INVOKE_FOOTER("1");
}
int lua_ImGui_TextEditor_undo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("imgui.TextEditor", "imgui.TextEditor:undo");
	LUA_TRY_INVOKE(1, static_cast<void(TextEditor::*)(int)>(&TextEditor::Undo));
	LUA_TRY_INVOKE(0, [](TextEditor* obj){{return obj->Undo();}});
	LUA_INVOKE_FOOTER("0,1");
}

static int lua_ImGui_TextEditor_new_collect(lua_State* tolua_S)
{
    TextEditor* self = (TextEditor*)tolua_tousertype(tolua_S, 1, 0);
    Mtolua_delete(self);
    return 0;
}

int lua_ImGui_TextEditor_new(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (!tolua_isusertable(tolua_S, 1, "imgui.TextEditor", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
    {
            tolua_error(tolua_S, "#ferror in function 'new'.", &tolua_err);
            return 0;
    }
    else
    {
        TextEditor* tolua_ret = (TextEditor*)Mtolua_new((TextEditor)());
        tolua_pushusertype(tolua_S, (void*)tolua_ret, "imgui.TextEditor");
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
    }
    return 1;
}
int luaReg_imguiTextEditor_imguiTextEditor(lua_State* lua_S)
{
	LUA_ENTRY("imgui");
	LUA_CLS_DEF_BASE(TextEditor, "TextEditor", "imgui.TextEditor", nullptr, "", nullptr, lua_ImGui_TextEditor_new_collect);
    LUA_METHOD("addLanguageIdentifier", lua_ImGui_TextEditor_addLanguageIdentifier);
    LUA_METHOD("addLanguagePreprocIdentifier", lua_ImGui_TextEditor_addLanguagePreprocIdentifier);
    LUA_METHOD("canRedo", lua_ImGui_TextEditor_canRedo);
    LUA_METHOD("canUndo", lua_ImGui_TextEditor_canUndo);
    LUA_METHOD("copy", lua_ImGui_TextEditor_copy);
    LUA_METHOD("cut", lua_ImGui_TextEditor_cut);
    LUA_METHOD("delete", lua_ImGui_TextEditor_delete);
    LUA_METHOD("getCurrentLineText", lua_ImGui_TextEditor_getCurrentLineText);
    LUA_METHOD("getCursorPosition", lua_ImGui_TextEditor_getCursorPosition);
    LUA_METHOD("getHoveredCoordinates", lua_ImGui_TextEditor_getHoveredCoordinates);
    LUA_METHOD("getHoveredDeclaration", lua_ImGui_TextEditor_getHoveredDeclaration);
    LUA_METHOD("getHoveredWord", lua_ImGui_TextEditor_getHoveredWord);
    LUA_METHOD("getHoveredWordIndex", lua_ImGui_TextEditor_getHoveredWordIndex);
    LUA_METHOD("getPalette", lua_ImGui_TextEditor_getPalette);
    LUA_METHOD("getSelectedText", lua_ImGui_TextEditor_getSelectedText);
    LUA_METHOD("getTabSize", lua_ImGui_TextEditor_getTabSize);
    LUA_METHOD("getText", lua_ImGui_TextEditor_getText);
    LUA_METHOD("getTextLines", lua_ImGui_TextEditor_getTextLines);
    LUA_METHOD("getTotalLines", lua_ImGui_TextEditor_getTotalLines);
    LUA_METHOD("hasSelection", lua_ImGui_TextEditor_hasSelection);
    LUA_METHOD("insertText", lua_ImGui_TextEditor_insertText);
    LUA_METHOD("isAutoTooltip", lua_ImGui_TextEditor_isAutoTooltip);
    LUA_METHOD("isColorizerEnabled", lua_ImGui_TextEditor_isColorizerEnabled);
    LUA_METHOD("isCursorPositionChanged", lua_ImGui_TextEditor_isCursorPositionChanged);
    LUA_METHOD("isHandleKeyboardInputsEnabled", lua_ImGui_TextEditor_isHandleKeyboardInputsEnabled);
    LUA_METHOD("isHandleMouseInputsEnabled", lua_ImGui_TextEditor_isHandleMouseInputsEnabled);
    LUA_METHOD("isImGuiChildIgnored", lua_ImGui_TextEditor_isImGuiChildIgnored);
    LUA_METHOD("isOverwrite", lua_ImGui_TextEditor_isOverwrite);
    LUA_METHOD("isReadOnly", lua_ImGui_TextEditor_isReadOnly);
    LUA_METHOD("isShowingShortTabGlyphs", lua_ImGui_TextEditor_isShowingShortTabGlyphs);
    LUA_METHOD("isShowingWhitespaces", lua_ImGui_TextEditor_isShowingWhitespaces);
    LUA_METHOD("isTextChanged", lua_ImGui_TextEditor_isTextChanged);
    LUA_METHOD("moveBottom", lua_ImGui_TextEditor_moveBottom);
    LUA_METHOD("moveDown", lua_ImGui_TextEditor_moveDown);
    LUA_METHOD("moveEnd", lua_ImGui_TextEditor_moveEnd);
    LUA_METHOD("moveHome", lua_ImGui_TextEditor_moveHome);
    LUA_METHOD("moveLeft", lua_ImGui_TextEditor_moveLeft);
    LUA_METHOD("moveRight", lua_ImGui_TextEditor_moveRight);
    LUA_METHOD("moveTop", lua_ImGui_TextEditor_moveTop);
    LUA_METHOD("moveUp", lua_ImGui_TextEditor_moveUp);
    LUA_METHOD("paste", lua_ImGui_TextEditor_paste);
    LUA_METHOD("redo", lua_ImGui_TextEditor_redo);
    LUA_METHOD("render", lua_ImGui_TextEditor_render);
    LUA_METHOD("selectAll", lua_ImGui_TextEditor_selectAll);
    LUA_METHOD("selectWordUnderCursor", lua_ImGui_TextEditor_selectWordUnderCursor);
    LUA_METHOD("setAutoTooltip", lua_ImGui_TextEditor_setAutoTooltip);
    LUA_METHOD("setBreakpoints", lua_ImGui_TextEditor_setBreakpoints);
    LUA_METHOD("setColorizerEnable", lua_ImGui_TextEditor_setColorizerEnable);
    LUA_METHOD("setCursorPosition", lua_ImGui_TextEditor_setCursorPosition);
    LUA_METHOD("setErrorMarkers", lua_ImGui_TextEditor_setErrorMarkers);
    LUA_METHOD("setHandleKeyboardInputs", lua_ImGui_TextEditor_setHandleKeyboardInputs);
    LUA_METHOD("setHandleMouseInputs", lua_ImGui_TextEditor_setHandleMouseInputs);
    LUA_METHOD("setImGuiChildIgnored", lua_ImGui_TextEditor_setImGuiChildIgnored);
    LUA_METHOD("setLanguageAngelScript", lua_ImGui_TextEditor_setLanguageAngelScript);
    LUA_METHOD("setLanguageC", lua_ImGui_TextEditor_setLanguageC);
    LUA_METHOD("setLanguageCPlusPlus", lua_ImGui_TextEditor_setLanguageCPlusPlus);
    LUA_METHOD("setLanguageDefinition", lua_ImGui_TextEditor_setLanguageDefinition);
    LUA_METHOD("setLanguageGLSL", lua_ImGui_TextEditor_setLanguageGLSL);
    LUA_METHOD("setLanguageHLSL", lua_ImGui_TextEditor_setLanguageHLSL);
    LUA_METHOD("setLanguageLua", lua_ImGui_TextEditor_setLanguageLua);
    LUA_METHOD("setLanguageSQL", lua_ImGui_TextEditor_setLanguageSQL);
    LUA_METHOD("setPalette", lua_ImGui_TextEditor_setPalette);
    LUA_METHOD("setPaletteDark", lua_ImGui_TextEditor_setPaletteDark);
    LUA_METHOD("setPaletteLight", lua_ImGui_TextEditor_setPaletteLight);
    LUA_METHOD("setPaletteRetroBlue", lua_ImGui_TextEditor_setPaletteRetroBlue);
    LUA_METHOD("setReadOnly", lua_ImGui_TextEditor_setReadOnly);
    LUA_METHOD("setSelection", lua_ImGui_TextEditor_setSelection);
    LUA_METHOD("setSelectionEnd", lua_ImGui_TextEditor_setSelectionEnd);
    LUA_METHOD("setSelectionStart", lua_ImGui_TextEditor_setSelectionStart);
    LUA_METHOD("setShowShortTabGlyphs", lua_ImGui_TextEditor_setShowShortTabGlyphs);
    LUA_METHOD("setShowWhitespaces", lua_ImGui_TextEditor_setShowWhitespaces);
    LUA_METHOD("setTabSize", lua_ImGui_TextEditor_setTabSize);
    LUA_METHOD("setText", lua_ImGui_TextEditor_setText);
    LUA_METHOD("setTextLines", lua_ImGui_TextEditor_setTextLines);
    LUA_METHOD("undo", lua_ImGui_TextEditor_undo);
    LUA_METHOD("new", lua_ImGui_TextEditor_new);
	luaReg_imguiTextEditor_imguiTextEditorPaletteIndex(lua_S);
	luaReg_imguiTextEditor_imguiTextEditorSelectionMode(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
#else
int luaReg_imguiTextEditor_imguiTextEditor(lua_State* lua_S)
{
    return 0;
}
#endif
