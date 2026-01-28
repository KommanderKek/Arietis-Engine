#include "panel.h"

Panel::Panel(float x, float y, float width, float height) {
	m_bounds.x = x;
	m_bounds.y = y;
	m_bounds.w = width;
	m_bounds.h = height;
}

Widget* Panel::create_widget(float x, float y, float width, float height, int render_layer, SDL_Renderer* renderer) {
	m_widgets.emplace_back(x, y, width, height, render_layer, renderer);
	return &m_widgets.back();
}