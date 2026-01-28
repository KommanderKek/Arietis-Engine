#pragma once

#include "SDL3/SDL.h"

#include <vector>

class Widget;

class RenderSystem {
private:
	std::vector<Widget*> m_renderables;

public:
	void render(SDL_Renderer* renderer);
	void set_render_target(SDL_Renderer* renderer, SDL_Texture* texture);
	void add_renderable(Widget* renderable);
	void remove_renderable(Widget* renderable);

private:
	void sort_renderables();
};