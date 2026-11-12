#include "mouse_event.hh"
#include <algorithm>

void MouseEventManager::AddHandler(OnMouseEvent handler) {
	handlers.push_back(handler);
}

void MouseEventManager::Trigger(MouseEvent* event) {
	std::for_each(handlers.begin(), handlers.end(), [&event](OnMouseEvent& handler) {
			handler(event);
		});
}
