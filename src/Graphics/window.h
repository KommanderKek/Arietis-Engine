#pragma once

#include "widget.h"

#include <SDL3/SDL.h>

#include <vector>
#include <string>

class Window {
private:
	SDL_Window* m_window;

	std::string m_title;
	int m_width;
	int m_height;
	SDL_WindowFlags m_flags;

	SDL_Renderer* m_renderer;

	std::vector<Widget> widgets;

public:
	Window();
	Window(std::string title, int width, int height, SDL_WindowFlags flags);
	~Window();

	void add_widget(float x, float y, float width, float height);

	void draw();
};