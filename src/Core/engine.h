#pragma once

#include "../Events/eventsystem.h"
#include "../Render/rendersystem.h"
#include "../Update/updatesystem.h"
#include "../Graphics/image.h"
#include "../Graphics/button.h"

class Engine {
private:
	std::unique_ptr<EventSystem> m_event_system;
	std::unique_ptr<UpdateSystem> m_update_system;
	std::unique_ptr<RenderSystem> m_render_system;
	std::vector<std::shared_ptr<WindowRenderer>> m_windows;
	bool m_initialized;
	bool m_running;

public:
	Engine();
	void initialize();
	void run();
	void shutdown();
	void register_window(std::shared_ptr<WindowRenderer> window);

private:
	void stop();
	void process_events();
	void update();
	void render();
};