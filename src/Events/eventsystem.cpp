#include "eventsystem.h"

EventSystem::EventSystem() {
	m_quit_request = false;
}

void EventSystem::poll_events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			m_quit_request = true;
		}
	}
}

bool EventSystem::quit_requested() {
	return m_quit_request;
}