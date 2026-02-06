#include "engine.h"

Engine::Engine() {
	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_running = false;
	m_initialized = false;
}

void Engine::initialize() {
	SDL_Init(SDL_INIT_VIDEO);

	m_event_system = std::make_unique<EventSystem>();
	m_render_system = std::make_unique<RenderSystem>();
	m_update_system = std::make_unique<UpdateSystem>();

	m_running = true;
	m_initialized = true;
}

void Engine::deinit() {
	if (!m_initialized) {
		return;
	}
	SDL_Quit();
}

void Engine::run() {
	while (m_running) {
		process_events();
		update();
		render();
	}
	deinit();
}

void Engine::register_window(std::shared_ptr<WindowRenderer> window) {
	m_render_system->add_window(window);
	m_update_system->add_window(window);
}

void Engine::process_events() {
	m_event_system->poll_events();
	if (m_event_system->quit_requested()) {
		stop();
	}
}

void Engine::update() {
	m_update_system->frame_update();
}

void Engine::render() {
	m_render_system->render_windows();
}

void Engine::stop() {
	m_running = false;
}