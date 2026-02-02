#pragma once

#include "SDL3/SDL.h"

#include <vector>
#include <memory>

#include "widget.h"

class Panel {
private:
	SDL_FRect m_bounds;
	std::vector<std::shared_ptr<Widget>> m_widgets;

public:
	Panel(float x, float y, float width, float height);
	void add_widget(std::shared_ptr<Widget> widget);
	void remove_widget(std::shared_ptr<Widget> widget);
	std::vector<std::shared_ptr<Widget>> get_widgets();
};