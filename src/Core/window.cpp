#include "window.h"

#include <SDL3/SDL.h>

#include <algorithm>

using namespace Arietis::Core;

Window::Window(std::string title, int width, int height, SDL_WindowFlags flags) {
	m_window = SDL_CreateWindow(title.c_str(), width, height, flags);
	m_renderer = SDL_CreateRenderer(m_window, nullptr);
	SDL_SetRenderTarget(m_renderer, nullptr);

	m_title = title;
	m_width = width;
	m_height = height;
	m_flags = flags;
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void Window::add_menu(std::shared_ptr<UI::Menu> menu) {
	m_menus.push_back(menu);
}

void Window::remove_menu(std::shared_ptr<UI::Menu> menu) {
	std::vector<std::shared_ptr<UI::Menu>>::iterator it = std::find(m_menus.begin(), m_menus.end(), menu);
	if (it != m_menus.end()) {
		m_menus.erase(it);
	}
}

void Window::render_menus() {
	SDL_SetRenderTarget(m_renderer, NULL);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	if (!m_menus.empty()) {
		for (std::shared_ptr<UI::Menu> menu : m_menus) {
			menu->render_widgets(m_renderer);
		}
	}
	SDL_RenderPresent(m_renderer);
}

void Window::dispatch_event(SDL_Event* event) {
	// Only handle events for top-most enabled menu
	for (int i = m_menus.size() - 1; i >= 0; i--) {
		std::shared_ptr<UI::Menu> menu = m_menus[i];
		if (menu->get_enabled()) {
			menu->handle_event(event);
			return;
		}
	}
}

SDL_Window* Window::get_sdl_window() {
	return m_window;
}