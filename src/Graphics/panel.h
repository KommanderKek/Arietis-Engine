#pragma once

#include "SDL3/SDL.h"

#include <vector>

#include "widget.h"

class Panel {
private:
	SDL_FRect m_bounds;
	std::vector<Widget> m_widgets;

public:
	Panel(float x, float y, float width, float height);
	Widget* create_widget(float x, float y, float width, float height, int render_layer, SDL_Renderer* renderer);
};