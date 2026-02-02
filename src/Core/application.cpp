#include "application.h"

Application::Application() {
	m_event_system = nullptr;
	m_render_system = nullptr;
	m_update_system = nullptr;
	m_running = false;
	m_initialized = false;
}

void Application::initialize() {
	SDL_Init(SDL_INIT_VIDEO);

	m_event_system = std::make_unique<EventSystem>();
	m_render_system = std::make_unique<RenderSystem>();
	m_update_system = std::make_unique<UpdateSystem>();

	std::shared_ptr<WindowRenderer> main_window = std::make_shared<WindowRenderer>("Arietis Engine", 1920, 1080, SDL_WINDOW_RESIZABLE);
	std::shared_ptr<GUI> main_menu = std::make_shared<GUI>();
	std::shared_ptr<Panel> panel = std::make_shared<Panel>(0.0f, 0.0f, 1920.0f, 1080.0f);

	std::shared_ptr<Widget> widget1 = std::make_shared<Widget>(100.0f, 100.0f, 100.0f, 100.0f, 0, 255, 0, 255, 0);
	std::shared_ptr<Widget> widget2 = std::make_shared<Widget>(150.0f, 150.0f, 100.0f, 100.0f, 255, 0, 0, 255, 1);

	main_window->add_gui(main_menu);
	m_render_system->add_window(main_window);

	panel->add_widget(widget1);
	panel->add_widget(widget2);
	main_menu->add_panel(panel);

	m_running = true;
	m_initialized = true;
}

void Application::deinit() {
	if (!m_initialized) {
		return;
	}
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
	m_update_system->frame_update();
}

void Application::render() {
	m_render_system->render_windows();
}

void Application::stop() {
	m_running = false;
}