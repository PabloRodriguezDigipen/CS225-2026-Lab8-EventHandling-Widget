#pragma once
#include "../Framework/entity.hh"
#include "AECore/inc/AEEngine.h"
#include "mouse_event.hh"

class Button : public Entity {
public:
	AEVec2 position;
	AEVec2 size;
	unsigned int color;
	const char* text;

	Button(AEVec2 pos, AEVec2 siz, unsigned int col, const char* txt);

	void Update() override;
	void Draw() override;

	void OnMouseClick(MouseEvent* event);
};
