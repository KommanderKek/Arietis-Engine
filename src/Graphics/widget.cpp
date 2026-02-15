#include "widget.h"

#include <SDL3/SDL.h>

Widget::Widget(float x_pos, float y_pos, float width, float height, int render_layer) {
	m_color = {128, 128, 128, 255};

	m_render_layer = render_layer;
	m_frect = {x_pos, y_pos, width, height};

	m_texture = nullptr;
	m_file_name = "";

	m_visible = true;
	m_enabled = true;
}

Widget::~Widget() {
	if (m_texture) {
		SDL_DestroyTexture(m_texture);
	}
}

void Widget::draw(SDL_Renderer* renderer) {
	if (!m_visible) {
		return;
	}
	if (!m_texture) {
		load_texture(renderer);
	}
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawColor(renderer, m_color[0], m_color[1], m_color[2], m_color[3]);
	SDL_RenderFillRect(renderer, &m_frect);
}

int Widget::get_render_layer() {
	return m_render_layer;
}

SDL_FRect* Widget::get_frect() {
	return &m_frect;
}

void Widget::set_render_layer(int render_layer) {
	m_render_layer = render_layer;
}

void Widget::set_file_name(std::string file_name) {
	m_file_name = file_name;
	if (m_texture) {
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

void Widget::set_color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
	m_color = {red, green, blue, alpha};
}

void Widget::set_visible(bool visible) {
	m_visible = visible;
}

void Widget::set_enabled(bool enabled) {
	m_enabled = enabled;
}

void Widget::load_texture(SDL_Renderer* renderer) {
	SDL_Surface* surface = SDL_LoadSurface(m_file_name.c_str());
	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
}