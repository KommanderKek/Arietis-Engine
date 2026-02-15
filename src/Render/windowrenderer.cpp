#include "windowrenderer.h"
#include "../Graphics/widget.h"
#include "../Graphics/gui.h"

#include <algorithm>

WindowRenderer::WindowRenderer(std::string title, int width, int height, SDL_WindowFlags flags) {
	m_window = SDL_CreateWindow(title.c_str(), width, height, flags);
	m_renderer = SDL_CreateRenderer(m_window, nullptr);
	SDL_SetRenderTarget(m_renderer, nullptr);

	m_title = title;
	m_width = width;
	m_height = height;
	m_flags = flags;
}

WindowRenderer::~WindowRenderer() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void WindowRenderer::add_gui(std::shared_ptr<GUI> gui) {
	m_guis.push_back(gui);
}

void WindowRenderer::remove_gui(std::shared_ptr<GUI> gui) {
	std::vector<std::shared_ptr<GUI>>::iterator it = std::find(m_guis.begin(), m_guis.end(), gui);
	if (it == m_guis.end()) {
		return;
	}
	m_guis.erase(it);
}

void WindowRenderer::render_guis() {
	SDL_SetRenderTarget(m_renderer, NULL);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	if (!m_guis.empty()) {
		for (std::shared_ptr<GUI> gui : m_guis) {
			gui->render_widgets(m_renderer);
		}
	}
	SDL_RenderPresent(m_renderer);
}

void WindowRenderer::dispatch_event(SDL_Event* event) {
	// Only handle events for top-most enabled GUI
	for (int i = m_guis.size() - 1; i >= 0; i--) {
		std::shared_ptr<GUI> gui = m_guis[i];
		if (gui->get_enabled()) {
			gui->handle_event(event);
			return;
		}
	}
}

SDL_Window* WindowRenderer::get_sdl_window() {
	return m_window;
}