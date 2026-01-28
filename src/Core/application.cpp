#include "application.h"

#include <SDL3/SDL.h>

Application::Application() {
	m_main_window = nullptr;
	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_running = false;
}

void Application::initialize() {
	SDL_Init(SDL_INIT_VIDEO);

	m_event_system = std::make_unique<EventSystem>();

	m_main_window = std::make_unique<Window>("Arietis Engine", 1920, 1080, SDL_WINDOW_RESIZABLE);
	m_main_window->add_widget(100, 100, 100, 100);
	m_main_window->add_widget(200, 200, 100, 100);
	m_main_window->add_widget(500, 500, 500, 500);

	m_running = true;
}

void Application::deinit() {
	m_main_window.reset();
	SDL_Quit();
}

void Application::run() {
	while (m_running) {
		process_events();
		update();
		render();
	}
	deinit();
}

void Application::process_events() {
	m_event_system->poll_events();
	if (m_event_system->quit_requested()) {
		stop();
	}
}

void Application::update() {
}

void Application::render() {
	m_main_window->draw();
}

void Application::stop() {
	m_running = false;
}