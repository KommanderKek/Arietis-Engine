#include "window.h"
#include "widget.h"

#include <SDL3/SDL.h>

#include <string>
#include <vector>

Window::Window(std::string title, int width, int height, SDL_WindowFlags flags) {
	m_window = SDL_CreateWindow(title.c_str(), width, height, flags);

	m_title = title;
	m_width = width;
	m_height = height;
	m_flags = flags;

	m_renderer = SDL_CreateRenderer(m_window, nullptr);
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void Window::add_widget(float x, float y, float width, float height) {
	Widget widget = Widget(x, y, width, height, m_renderer);
	widgets.push_back(widget);
}

void Window::draw() {
	SDL_SetRenderTarget(m_renderer, nullptr);
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_renderer);
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i].draw();
	}
	SDL_RenderPresent(m_renderer);
}