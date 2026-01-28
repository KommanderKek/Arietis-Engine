#pragma once

#include <SDL3/SDL.h>

class Widget {
protected:
	SDL_FRect m_rect;
	SDL_Texture* m_texture;
	int m_render_layer;

public:
	Widget(float x, float y, float width, float height, int render_layer, SDL_Renderer* renderer);
	~Widget();
	void draw(SDL_Renderer* renderer);
	int get_render_layer();
};