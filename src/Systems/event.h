#pragma once

#include "Core/window.h"

#include <SDL3/SDL.h>

namespace Arietis::Systems {
	class Event {
	private:
		bool m_quit_request;

	public:
		Event();
		void poll_events(std::vector<std::shared_ptr<Core::Window>> windows);
		bool get_quit_request();
		void send_quit_request();
	};
}