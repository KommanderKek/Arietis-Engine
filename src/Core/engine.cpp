#include "engine.h"

using namespace Arietis::Core;

Engine::Engine() {
	m_event = nullptr;
	m_render = nullptr;
	m_update = nullptr;
	m_initialized = false;
	m_running = false;
}

void Engine::initialize() {
	if (m_initialized) {
		return;
	}

	SDL_Init(SDL_INIT_VIDEO);

	m_event = std::make_unique<Systems::Event>();
	m_render = std::make_unique<Systems::Render>();
	m_update = std::make_unique<Systems::Update>();

	m_initialized = true;
	m_running = true;
}

void Engine::shutdown() {
	if (!m_initialized) {
		return;
	}

	m_event.reset();
	m_render.reset();
	m_update.reset();

	m_event = nullptr;
	m_render = nullptr;
	m_update = nullptr;
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

void Engine::register_window(std::shared_ptr<Window> window) {
	if (!m_initialized) {
		return;
	}
	m_windows.push_back(window);
}

void Engine::process_events() {
	m_event->poll_events(m_windows);
	if (m_event->get_quit_request()) {
		stop();
	}
}

void Engine::update() {
	m_update->frame_update();
}

void Engine::render() {
	m_render->render_windows(m_windows);
}

void Engine::stop() {
	m_running = false;
}