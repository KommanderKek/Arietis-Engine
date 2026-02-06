#pragma once

#include "widget.h"
#include "image.h"

#include <memory>
#include <vector>

class GUI {
private:
	std::vector<std::shared_ptr<Widget>> m_widgets;
	bool m_widgets_sorted;

public:
	void add_widget(std::shared_ptr<Widget> widget);
	void remove_widget(std::shared_ptr<Widget> widget);
	void render_widgets(SDL_Renderer* renderer);
	void create_textures(SDL_Renderer* renderer);

private:
	void sort_widgets();
};