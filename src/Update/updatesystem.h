#pragma once

#include "telemetry.h"
#include "../Graphics/windowrenderer.h"

#include <memory>

class UpdateSystem {
private:
	std::unique_ptr<Telemetry> telemetry;
	std::vector<std::shared_ptr<WindowRenderer>> m_windows;

public:
	UpdateSystem();
	void frame_update();
	void add_window(std::shared_ptr<WindowRenderer> window);
	void remove_window(std::shared_ptr<WindowRenderer> window);

private:
	void frame_rate();
};