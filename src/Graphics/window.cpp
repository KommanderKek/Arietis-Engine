#include "window.h"

#include <string>

Window::Window(std::string title, int width, int height, SDL_WindowFlags flags) {
	m_window = SDL_CreateWindow(title.c_str(), width, height, flags);
	m_renderer = SDL_CreateRenderer(m_window, nullptr);

	m_title = title;
	m_width = width;
	m_height = height;
	m_flags = flags;
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

SDL_Renderer* Window::get_renderer() {
	return m_renderer;
}