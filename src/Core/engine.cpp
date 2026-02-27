#include "engine.h"

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

using namespace Arietis::Core;

Engine::Engine() {
	m_events = nullptr;
	m_renderer = nullptr;
	m_updates = nullptr;
	m_initialized = false;
	m_running = false;
}

void Engine::initialize() {
	if (m_initialized) {
		return;
	}

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	m_events = std::make_unique<Systems::Events>();
	m_renderer = std::make_unique<Systems::Renderer>();
	m_updates = std::make_unique<Systems::Updates>();

	m_initialized = true;
	m_running = true;
}

void Engine::shutdown() {
	if (!m_initialized) {
		return;
	}

	m_events.reset();
	m_renderer.reset();
	m_updates.reset();

	m_events = nullptr;
	m_renderer = nullptr;
	m_updates = nullptr;
	m_running = false;

	TTF_Quit();
	SDL_Quit();
}

void Engine::run() {
	if (!m_initialized) {
		return;
	}

	while (m_running) {
		process_events();
		update();
		render();
	}
}

void Engine::register_window(std::shared_ptr<Window> window) {
	if (!m_initialized) {
		return;
	}
	m_windows.push_back(window);
}

void Engine::process_events() {
	m_events->poll_events(m_windows);
	if (m_events->get_quit_request()) {
		stop();
	}
}

void Engine::update() {
	m_updates->frame_update();
}

void Engine::render() {
	m_renderer->render_windows(m_windows);
}

void Engine::stop() {
	m_running = false;
}