#include "gui.h"

#include <algorithm>

GUI::GUI() {
	m_widgets_set = false;
}

void GUI::add_panel(std::shared_ptr<Panel> panel) {
	m_panels.push_back(panel);
	m_widgets_set = false;
}

void GUI::remove_panel(std::shared_ptr<Panel> panel) {
	std::vector<std::shared_ptr<Panel>>::iterator it = std::find(m_panels.begin(), m_panels.end(), panel);
	if (it == m_panels.end()) {
		return;
	}
	m_panels.erase(it);
	m_widgets_set = false;
}

void GUI::render_widgets(SDL_Renderer* renderer) {
	if (!m_widgets_set) {
		set_widgets();
		m_widgets_set = true;
	}
	for (std::shared_ptr<Widget> widget : m_widgets) {
		widget->draw(renderer);
	}
}

void GUI::set_widgets() {
	// clear widget array
	m_widgets.clear();

	// collect widgets from panels
	for (std::shared_ptr<Panel> panel : m_panels) {
		std::vector<std::shared_ptr<Widget>> widgets = panel->get_widgets();
		m_widgets.insert(m_widgets.end(), widgets.begin(), widgets.end());
	}

	// sort widgets by render layer
	std::stable_sort(m_widgets.begin(), m_widgets.end(),
		[](std::shared_ptr<Widget> a, std::shared_ptr<Widget> b) {
			return a->get_render_layer() < b->get_render_layer();
		}
	);
}