#include "menu.h"
#include "button.h"

#include <algorithm>

using namespace Arietis::UI;

Menu::Menu() {
	m_widgets_sorted = false;
	m_enabled = true;
}

void Menu::add_widget(std::shared_ptr<Widget> widget) {
	m_widgets.push_back(widget);
	m_widgets_sorted = false;
}

void Menu::remove_widget(std::shared_ptr<Widget> widget) {
	std::vector<std::shared_ptr<Widget>>::iterator it = std::find(m_widgets.begin(), m_widgets.end(), widget);
	if (it == m_widgets.end()) {
		return;
	}
	m_widgets.erase(it);
}

void Menu::render_widgets(SDL_Renderer* renderer) {
	if (!m_widgets_sorted) {
		sort_widgets();
		m_widgets_sorted = true;
	}
	for (std::shared_ptr<Widget> widget : m_widgets) {
		widget->draw(renderer);
	}
}

void Menu::handle_event(SDL_Event* event) {
	// check widget events
	if (!m_widgets_sorted) {
		sort_widgets();
		m_widgets_sorted = true;
	}
	for (int i = m_widgets.size() - 1; i >= 0; i--) {
		std::shared_ptr<Widget> widget = m_widgets[i];
		if ((std::dynamic_pointer_cast<Button>(widget) != nullptr) and
				(cursor_contains(event, widget->get_frect()))) {
			SDL_Log("Clicked");
			return;
		}
	}
}

bool Menu::get_enabled() {
	return m_enabled;
}

void Menu::set_enabled(bool enabled) {
	m_enabled = enabled;
}

void Menu::sort_widgets() {
	std::stable_sort(m_widgets.begin(), m_widgets.end(),
		[](std::shared_ptr<Widget> a, std::shared_ptr<Widget> b) {
			return a->get_render_layer() < b->get_render_layer();
		}
	);
}

bool Menu::cursor_contains(SDL_Event* event, SDL_FRect* dest_frect) {
	float mouse_x = event->button.x;
	float mouse_y = event->button.y;
	float dest_x = dest_frect->x;
	float dest_y = dest_frect->y;
	float dest_w = dest_frect->w;
	float dest_h = dest_frect->h;

	if ((mouse_x >= dest_x and mouse_x <= dest_x + dest_w) and
			(mouse_y >= dest_y and mouse_y <= dest_y + dest_h)) {
		return true;
	}
	return false;
}