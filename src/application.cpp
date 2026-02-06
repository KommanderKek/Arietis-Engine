#include "application.h"

void Application::init() {
	engine.initialize();

	std::shared_ptr<WindowRenderer> window = std::make_shared<WindowRenderer>("Arietis Engine", 1920, 1080, SDL_WINDOW_RESIZABLE);
	std::shared_ptr<GUI> main_menu = std::make_shared<GUI>();
	std::shared_ptr<Widget> widget1 = std::make_shared<Widget>(100.0f, 100.0f, 100.0f, 100.0f, 255, 0, 0, 255, 1);
	std::shared_ptr<Widget> widget2 = std::make_shared<Widget>(150.0f, 150.0f, 100.0f, 100.0f, 0, 255, 0, 255, 0);
	std::shared_ptr<Image> image = std::make_shared<Image>(200.0f, 200.0f, 100.0f, 100.0f, 2, "sample.bmp");

	main_menu->add_widget(widget1);
	main_menu->add_widget(widget2);
	main_menu->add_widget(image);
	window->add_gui(main_menu);
	engine.register_window(window);
}

void Application::run() {
	engine.run();
}