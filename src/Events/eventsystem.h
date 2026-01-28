#pragma once

#include "SDL3/SDL.h"

class EventSystem {
private:
	bool m_quit_request;
public:
	EventSystem();
	void poll_events();
	bool quit_requested();
};