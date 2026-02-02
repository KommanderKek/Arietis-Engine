#pragma once

#include "widget.h"
#include "gui.h"

#include <SDL3/SDL.h>

#include <vector>
#include <memory>
#include <string>

class WindowRenderer {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::string m_title;
	int m_width;
	int m_height;
	SDL_WindowFlags m_flags;

	std::vector<std::shared_ptr<GUI>> m_guis;

public:
	WindowRenderer(std::string title, int width, int height, SDL_WindowFlags flags);
	~WindowRenderer();
	void add_gui(std::shared_ptr<GUI> gui);
	void remove_gui(std::shared_ptr<GUI> gui);
	void render_guis();
};