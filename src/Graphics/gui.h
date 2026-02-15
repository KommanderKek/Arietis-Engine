#pragma once

#include "widget.h"
#include "image.h"

#include <memory>
#include <vector>

class GUI {
private:
	std::vector<std::shared_ptr<Widget>> m_widgets;
	bool m_widgets_sorted;
	bool m_enabled;

public:
	GUI();
	void add_widget(std::shared_ptr<Widget> widget);
	void remove_widget(std::shared_ptr<Widget> widget);
	void render_widgets(SDL_Renderer* renderer);
	void handle_event(SDL_Event* event);
	bool get_enabled();
	void set_enabled(bool enabled);


private:
	void sort_widgets();
	bool cursor_contains(SDL_Event* event, SDL_FRect* dest_frect);
};