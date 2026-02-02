#pragma once

#include "telemetry.h"

#include <memory>

class UpdateSystem {
private:
	std::unique_ptr<Telemetry> telemetry;
	int m_fps_cap;
	bool m_make_fixed_fps;

public:
	UpdateSystem();
	void frame_update();
	void set_fixed_fps(bool make_fixed_fps, int fps_cap);

private:
	void frame_rate();
};