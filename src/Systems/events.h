#pragma once

#include "Core/window.h"

#include <memory>
#include <vector>

namespace Arietis::Systems {

class Events {
private:
	bool m_quit_request;

public:
	Events();
	void poll_events(std::vector<std::shared_ptr<Core::Window>> windows);
	bool get_quit_request();
	void send_quit_request();
};

}