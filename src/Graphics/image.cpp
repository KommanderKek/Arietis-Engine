#include "image.h"

Image::Image(float x, float y, float width, float height, int render_layer, std::string file_name) :
		Widget(x, y, width, height, 0, 0, 0, 0, render_layer) {
	m_file_name = file_name;
	m_texture = nullptr;
}

Image::~Image() {
	if (m_texture) {
		SDL_DestroyTexture(m_texture);
	}
}

void Image::create_texture(SDL_Renderer* renderer) {
	SDL_Surface* surface = SDL_LoadSurface(m_file_name.c_str());
	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
}

void Image::draw(SDL_Renderer* renderer) {
	if (!m_visible || !m_texture) {
		return;
	}
	SDL_SetRenderTarget(renderer, m_texture);
	SDL_RenderTexture(renderer, m_texture, NULL, &m_frect);
}