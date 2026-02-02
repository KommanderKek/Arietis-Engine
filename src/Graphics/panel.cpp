#include "panel.h"

Panel::Panel(float x, float y, float width, float height) {
	m_bounds.x = x;
	m_bounds.y = y;
	m_bounds.w = width;
	m_bounds.h = height;
}

void Panel::add_widget(std::shared_ptr<Widget> widget) {
	m_widgets.push_back(widget);
}

void Panel::remove_widget(std::shared_ptr<Widget> widget) {
	std::vector<std::shared_ptr<Widget>>::iterator it = std::find(m_widgets.begin(), m_widgets.end(), widget);
	if (it == m_widgets.end()) {
		return;
	}
	m_widgets.erase(it);
}

std::vector<std::shared_ptr<Widget>> Panel::get_widgets() {
	return m_widgets;
}