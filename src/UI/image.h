#pragma once

#include "widget.h"

#include "SDL3/SDL.h"

#include <string>

namespace Arietis::UI {
	class Image : public Widget {
	public:
		Image(float x_pos, float y_pos, float width, float height, int render_layer, std::string file_name);
		Image(float x_pos, float y_pos, float width, float height, int render_layer);
		void draw(SDL_Renderer* renderer) override;
	};
}