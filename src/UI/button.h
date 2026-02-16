#pragma once

#include "widget.h"

#include "SDL3/SDL.h"

#include <string>
#include <functional>

namespace Arietis::UI {
	class Button : public Widget {
	private:
		std::string m_button_text;
		std::function<void()> m_click_action;

	public:
		Button(float x_pos, float y_pos, float width, float height, int render_layer);
		void draw(SDL_Renderer* renderer) override;
		void on_click();
		void set_action(std::function<void()> function);
		void set_button_text(std::string text);
	};
}