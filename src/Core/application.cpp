#include "application.h"
#include "../Graphics/gui.h"
#include "../Graphics/panel.h"

#include <SDL3/SDL.h>

Application::Application() {
	m_main_window = nullptr;

	m_main_menu = nullptr;

	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_running = false;
}

void Application::initialize() {
	SDL_Init(SDL_INIT_VIDEO);

	m_event_system = std::make_unique<EventSystem>();
	m_render_system = std::make_unique<RenderSystem>();

	m_main_window = std::make_unique<Window>("Arietis Engine", 1920, 1080, SDL_WINDOW_RESIZABLE);

	SDL_Renderer* renderer = m_main_window->get_renderer();

	m_main_menu = std::make_unique<GUI>();
	Panel* main_panel = m_main_menu->create_panel(0, 0, 1920, 1080);
	Widget* widget = main_panel->create_widget(100, 100, 500, 500, 0, renderer);

	m_render_system->add_renderable(widget);

	m_render_system->set_render_target(renderer, nullptr);

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
	m_render_system->render(m_main_window->get_renderer());
}

void Application::stop() {
	m_running = false;
}