#include "widget.h"

#include <SDL3/SDL.h>

Widget::Widget(float x, float y, float width, float height, SDL_Renderer* renderer) {
	m_renderer = renderer;
	m_rect = {x, y, width, height};
	m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, static_cast<int>(width), static_cast<int>(height));
}

Widget::~Widget() {
	SDL_DestroyTexture(m_texture);
}

void Widget::draw() {
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(m_renderer, &m_rect);
}