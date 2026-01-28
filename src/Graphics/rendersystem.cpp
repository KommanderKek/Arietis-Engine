#include "rendersystem.h"
#include "widget.h"

#include <vector>
#include <algorithm>

void RenderSystem::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	if (m_renderables.empty()) {
		return;
	}
	sort_renderables();
	for (Widget* renderable : m_renderables) {
		renderable->draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

void RenderSystem::set_render_target(SDL_Renderer* renderer, SDL_Texture* texture) {
	SDL_SetRenderTarget(renderer, texture);
}

void RenderSystem::add_renderable(Widget* renderable) {
	m_renderables.push_back(renderable);
}

void RenderSystem::remove_renderable(Widget* renderable) {
	std::vector<Widget*>::iterator it = std::find(m_renderables.begin(), m_renderables.end(), renderable);
	if (it == m_renderables.end()) {
		return;
	}
	m_renderables.erase(it);
}

void RenderSystem::sort_renderables() {
	std::stable_sort(m_renderables.begin(), m_renderables.end(), [](Widget* a, Widget* b) {
		return a->get_render_layer() < b->get_render_layer();
	});
}