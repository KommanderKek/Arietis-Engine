#include "button.h"

using namespace Arietis::UI;

Button::Button(float x_pos, float y_pos, float width, float height, int render_layer) :
		Widget(x_pos, y_pos, width, height, render_layer) {
}

void Button::draw(SDL_Renderer* renderer) {
	if (!m_visible) {
		return;
	}
	if (!m_texture) {
		load_texture(renderer);
	}
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawColor(renderer, m_color[0], m_color[1], m_color[2], m_color[3]);
	SDL_RenderFillRect(renderer, &m_frect);
}

void Button::click() {
	if (m_click_action) {
		m_click_action();
	}
}

void Button::set_button_text(std::string text) {
	m_button_text = text;
}

void Button::set_action(std::function<void()> function) {
	m_click_action = std::move(function);
}