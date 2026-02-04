#pragma once

#include "../Events/eventsystem.h"
#include "../Graphics/rendersystem.h"
#include "../Update/updatesystem.h"

class Engine {
private:
	std::unique_ptr<EventSystem> m_event_system;
	std::unique_ptr<UpdateSystem> m_update_system;
	std::unique_ptr<RenderSystem> m_render_system;
	bool m_running;
	bool m_initialized;

public:
	Engine();
	void initialize();
	void run();
	void register_window(std::shared_ptr<WindowRenderer> window);

private:
	void deinit();
	void stop();
	void process_events();
	void update();
	void render();
};