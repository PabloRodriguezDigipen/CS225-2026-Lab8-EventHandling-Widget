#include "button.hh"

Button::Button(AEVec2 pos, AEVec2 siz, unsigned int col, const char* txt)
	: position(pos), size(siz), color(col), text(txt) {}

void Button::Update() {

}

void Button::Draw() {
	AEGfxRect(position.x, position.y, 0, size.x, size.y, color);

	AEGfxPrint(position.x + AEGetSysWindowWidth() / 2, position.y + AEGetSysWindowHeight() / 2, color, text);
}

void Button::OnMouseClick(MouseEvent* event) {
	color = AE_COLORS_GREEN;
}
