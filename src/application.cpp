#include "application.h"

#include <memory>
#include <functional>

using namespace Arietis;

void action() {
	SDL_Log("Button Clicked!");
}

void Application::init() {
	m_engine.initialize();

	std::shared_ptr<Core::Window> window = std::make_shared<Core::Window>("Arietis Engine", 1920, 1080, SDL_WINDOW_RESIZABLE);
	std::shared_ptr<UI::Menu> main_menu = std::make_shared<UI::Menu>();
	std::shared_ptr<UI::Widget> widget1 = std::make_shared<UI::Widget>(100.0f, 100.0f, 100.0f, 100.0f, 1);
	std::shared_ptr<UI::Widget> widget2 = std::make_shared<UI::Widget>(150.0f, 150.0f, 100.0f, 100.0f, 0);
	widget1->set_color(255, 0, 0, 255);
	widget2->set_color(0, 255, 0, 255);
	std::shared_ptr<UI::Image> image = std::make_shared<UI::Image>(175.0f, 175.0f, 100.0f, 100.0f, 2, "sample.bmp");
	std::shared_ptr<UI::Button> button = std::make_shared<UI::Button>(300.0f, 300.0f, 100.0f, 100.0f, 0);
	button->set_color(0, 0, 255, 255);

	button->set_action(action);

	main_menu->add_widget(widget1);
	main_menu->add_widget(widget2);
	main_menu->add_widget(image);
	main_menu->add_widget(button);
	window->add_menu(main_menu);
	m_engine.register_window(window);
}

void Application::start() {
	m_engine.run();
}

void Application::deinit() {
	m_engine.shutdown();
}