#pragma once
#include "../Framework/event.hh"
#include "AECore/inc/AEEngine.h"
#include <functional>
#include <vector>

class MouseEvent : public Event {
	AEVec2 position;
};

typedef std::function<void(MouseEvent*)> OnMouseEvent;

class MouseEventManager {
protected:
	std::vector<OnMouseEvent> handlers;
public:
	void AddHandler(OnMouseEvent handler);
	void Trigger(MouseEvent* event);
};
