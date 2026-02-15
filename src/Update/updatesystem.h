#pragma once

#include "telemetry.h"
#include "../Render/windowrenderer.h"

#include <memory>

class UpdateSystem {
private:
	std::unique_ptr<Telemetry> m_telemetry;

public:
	UpdateSystem();
	void frame_update();
};