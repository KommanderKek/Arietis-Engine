#pragma once

#include "../Render/windowrenderer.h"

#include "SDL3/SDL.h"

class EventSystem {
private:
	bool m_quit_request;

public:
	EventSystem();
	void poll_events(std::vector<std::shared_ptr<WindowRenderer>> windows);
	bool get_quit_request();
	void send_quit_request();
};