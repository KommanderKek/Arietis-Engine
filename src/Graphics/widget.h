#pragma once

#include <SDL3/SDL.h>

#include <vector>

class Widget {
protected:
	SDL_FRect m_frect;
	std::vector<Uint8> m_color;
	int m_render_layer;
	bool m_visible;
	bool m_enabled;

public:
	Widget(float x, float y, float width, float height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, int render_layer);
	virtual void draw(SDL_Renderer* renderer);
	void set_visible(bool visible);
	void set_enabled(bool enabled);
	int get_render_layer();
};