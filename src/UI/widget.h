#pragma once

#include <SDL3/SDL.h>

#include <vector>
#include <string>

namespace Arietis::UI {
	class Widget {
	protected:
		SDL_FRect m_frect;
		std::vector<Uint8> m_color;
		std::string m_file_name;
		SDL_Texture* m_texture;
		int m_render_layer;
		bool m_visible;
		bool m_enabled;

	public:
		Widget(float x_pos, float y_pos, float width, float height, int render_layer);
		~Widget();
		virtual void draw(SDL_Renderer* renderer);
		int get_render_layer();
		SDL_FRect* get_frect();
		void set_render_layer(int render_layer);
		void set_file_name(std::string file_name);
		void set_color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
		void set_visible(bool visible);
		void set_enabled(bool enabled);

	protected:
		void load_texture(SDL_Renderer* renderer);
	};
}