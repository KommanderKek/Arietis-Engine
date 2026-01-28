#pragma once

#include <SDL3/SDL.h>

class Widget {

protected:

	SDL_FRect m_rect;
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;

public:

	Widget(float x, float y, float width, float height, SDL_Renderer* renderer);
	~Widget();

	void draw();
};