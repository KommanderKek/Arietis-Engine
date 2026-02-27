#pragma once

#include "Core/window.h"
#include "Systems/events.h"
#include "Systems/renderer.h"
#include "Systems/updates.h"

#include <vector>
#include <memory>

namespace Arietis::Core {

class Engine {
private:
	std::unique_ptr<Systems::Events> m_events;
	std::unique_ptr<Systems::Updates> m_updates;
	std::unique_ptr<Systems::Renderer> m_renderer;
	std::vector<std::shared_ptr<Window>> m_windows;
	bool m_initialized;
	bool m_running;

public:
	Engine();
	void initialize();
	void run();
	void shutdown();
	void register_window(std::shared_ptr<Window> window);

private:
	void stop();
	void process_events();
	void update();
	void render();
};

}