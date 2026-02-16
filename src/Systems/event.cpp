#include "event.h"

using namespace Arietis::Systems;

Event::Event() {
	m_quit_request = false;
}

void Event::poll_events(std::vector<std::shared_ptr<Core::Window>> windows) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_EVENT_QUIT:
				m_quit_request = true;
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				SDL_Window* sdl_window = SDL_GetWindowFromEvent(&event);
				for (std::shared_ptr<Core::Window> window : windows) {
					if (window->get_sdl_window() == sdl_window) {
						window->dispatch_event(&event);
					}
				}
				break;
		}
	}
}

bool Event::get_quit_request() {
	return m_quit_request;
}

void Event::send_quit_request() {
	m_quit_request = true;
}