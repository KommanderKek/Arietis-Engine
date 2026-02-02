#include "widget.h"

#include <SDL3/SDL.h>

Widget::Widget(float x, float y, float width, float height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, int render_layer) {
	m_color = {red, green, blue, alpha};

	m_render_layer = render_layer;
	m_frect = {x, y, width, height};

	m_visible = true;
	m_enabled = true;
}

void Widget::draw(SDL_Renderer* renderer) {
	if (!m_visible) {
		return;
	}
	SDL_SetRenderDrawColor(renderer, m_color[0], m_color[1], m_color[2], m_color[3]);
	SDL_RenderFillRect(renderer, &m_frect);
}

void Widget::set_visible(bool visible) {
	m_visible = visible;
}

void Widget::set_enabled(bool enabled) {
	m_enabled = enabled;
}

int Widget::get_render_layer() {
	return m_render_layer;
}