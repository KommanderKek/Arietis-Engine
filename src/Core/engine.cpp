#include "engine.h"

Engine::Engine() {
	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_initialized = false;
	m_running = false;
}

void Engine::initialize() {
	if (m_initialized) {
		return;
	}

	SDL_Init(SDL_INIT_VIDEO);

	m_event_system = std::make_unique<EventSystem>();
	m_render_system = std::make_unique<RenderSystem>();
	m_update_system = std::make_unique<UpdateSystem>();

	m_initialized = true;
	m_running = true;
}

void Engine::shutdown() {
	if (!m_initialized) {
		return;
	}

	m_event_system.reset();
	m_render_system.reset();
	m_update_system.reset();

	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_running = false;

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

void Engine::register_window(std::shared_ptr<WindowRenderer> window) {
	if (!m_initialized) {
		return;
	}
	m_windows.push_back(window);
}

void Engine::process_events() {
	m_event_system->poll_events(m_windows);
	if (m_event_system->get_quit_request()) {
		stop();
	}
}

void Engine::update() {
	m_update_system->frame_update();
}

void Engine::render() {
	m_render_system->render_windows(m_windows);
}

void Engine::stop() {
	m_running = false;
}