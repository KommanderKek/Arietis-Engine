#include "gui.h"

#include <algorithm>

void GUI::add_widget(std::shared_ptr<Widget> widget) {
	m_widgets.push_back(widget);
	m_widgets_sorted = false;
}

void GUI::remove_widget(std::shared_ptr<Widget> widget) {
	std::vector<std::shared_ptr<Widget>>::iterator it = std::find(m_widgets.begin(), m_widgets.end(), widget);
	if (it == m_widgets.end()) {
		return;
	}
	m_widgets.erase(it);
}

void GUI::render_widgets(SDL_Renderer* renderer) {
	if (!m_widgets_sorted) {
		sort_widgets();
		m_widgets_sorted = true;
	}
	for (std::shared_ptr<Widget> widget : m_widgets) {
		widget->draw(renderer);
	}
}

void GUI::sort_widgets() {
	std::stable_sort(m_widgets.begin(), m_widgets.end(),
		[](std::shared_ptr<Widget> a, std::shared_ptr<Widget> b) {
			return a->get_render_layer() < b->get_render_layer();
		}
	);
}