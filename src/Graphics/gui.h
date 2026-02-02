#pragma once

#include "Panel.h"

#include <memory>
#include <vector>

class GUI {
private:
	std::vector<std::shared_ptr<Panel>> m_panels;
	std::vector<std::shared_ptr<Widget>> m_widgets;
	bool m_widgets_set;

public:
	GUI();
	void add_panel(std::shared_ptr<Panel> panel);
	void remove_panel(std::shared_ptr<Panel> panel);
	void render_widgets(SDL_Renderer* renderer);

private:
	void set_widgets();
};