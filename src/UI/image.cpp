#include "image.h"

#include <SDL3/SDL.h>

using namespace Arietis::UI;

Image::Image(float x_pos, float y_pos, float width, float height, int render_layer, std::string file_name) :
		Widget(x_pos, y_pos, width, height, render_layer) {
	m_file_name = file_name;
}

Image::Image(float x_pos, float y_pos, float width, float height, int render_layer) :
	Widget(x_pos, y_pos, width, height, render_layer) {
}

void Image::draw(SDL_Renderer* renderer) {
	if (!m_visible) {
		return;
	}
	if (!m_texture) {
		load_textures(renderer);
	}
	SDL_RenderTexture(renderer, m_texture, NULL, &m_frect);
}