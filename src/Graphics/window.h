#pragma once

#include <SDL3/SDL.h>

#include <vector>
#include <string>

class Window {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::string m_title;
	int m_width;
	int m_height;
	SDL_WindowFlags m_flags;

public:
	Window(std::string title, int width, int height, SDL_WindowFlags flags);
	~Window();

	SDL_Renderer* get_renderer();
};