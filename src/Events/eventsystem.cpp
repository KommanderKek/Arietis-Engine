#include "eventsystem.h"

EventSystem::EventSystem() {
	m_quit_request = false;
}

void EventSystem::poll_events(std::vector<std::shared_ptr<WindowRenderer>> windows) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_EVENT_QUIT:
				m_quit_request = true;
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				SDL_Window* sdl_window = SDL_GetWindowFromEvent(&event);
				for (std::shared_ptr<WindowRenderer> window : windows) {
					if (window->get_sdl_window() == sdl_window) {
						window->dispatch_event(&event);
					}
				}
				break;
		}
	}
}

bool EventSystem::get_quit_request() {
	return m_quit_request;
}

void EventSystem::send_quit_request() {
	m_quit_request = true;
}