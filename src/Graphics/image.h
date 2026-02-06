#pragma once

#include "widget.h"

#include "SDL3/SDL.h"

#include <string>

class Image : public Widget {
private:
	SDL_Texture* m_texture;
	std::string m_file_name;

public:
	Image(float x, float y, float width, float height, int render_layer, std::string file_name);
	~Image();
	void create_texture(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer) override;
};