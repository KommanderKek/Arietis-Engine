#pragma once

#include "../Graphics/window.h"
#include "../Events/eventsystem.h"
#include "../Graphics/rendersystem.h"
#include "./updatesystem.h"

#include <memory>

class Application {
private:
	std::unique_ptr<Window> m_main_window;
	std::unique_ptr<EventSystem> m_event_system;
	std::unique_ptr<RenderSystem> m_render_system;
	std::unique_ptr<UpdateSystem> m_update_system;
	bool m_running;

public:
	Application();
	void initialize();
	void run();
	void stop();

private:
	void deinit();
	void process_events();
	void update();
	void render();
};