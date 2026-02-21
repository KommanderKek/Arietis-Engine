#pragma once

#include "Systems/event.h"
#include "Systems/render.h"
#include "Systems/update.h"
#include "UI/image.h"
#include "UI/button.h"

namespace Arietis::Core {
	class Engine {
	private:
		std::unique_ptr<Systems::Event> m_event;
		std::unique_ptr<Systems::Update> m_update;
		std::unique_ptr<Systems::Render> m_render;
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