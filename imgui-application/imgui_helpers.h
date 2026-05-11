#pragma once
#include <imgui.h>
typedef unsigned int GLuint;

namespace ImGuiHelpers {

inline float getMultilineInputHeight(float height) {
	if (height <= 0) {
		height = ImGui::GetTextLineHeight() * 8.0f;
		//default height found in imgui_widgets.cpp:
		//const ImVec2 frame_size = CalcItemSize(size_arg, CalcItemWidth(), (is_multiline ? g.FontSize * 8.0f : label_size.y) + style.FramePadding.y * 2.0f); // Arbitrary default of 8 lines high for multi-line
	}
	return height + 2 * ImGui::GetStyle().ItemSpacing.y;
}

/* Everything below this is from ImGui (sometimes with minor edits) */

inline void Tooltip(const char* text, float relative_width = 35.0f) {
	if (ImGui::BeginItemTooltip()) {
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * relative_width);
		ImGui::TextUnformatted(text);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

// Helper to display a little (?) mark which shows a tooltip when hovered.
// In your own code you may want to display an actual icon if you are using a merged icon fonts (see docs/FONTS.md)
inline void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    Tooltip(desc);
}

// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromMemory(const void* data, size_t data_size, GLuint* out_texture, int* out_width = nullptr, int* out_height = nullptr);

// Open and read a file, then forward to LoadTextureFromMemory()
bool LoadTextureFromFile(const char* file_name, GLuint* out_texture, int* out_width = nullptr, int* out_height = nullptr);

} // namespace ImGuiHelpers
