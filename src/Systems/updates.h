#pragma once

#include "telemetry.h"

#include <memory>

namespace Arietis::Systems {

class Updates {
private:
	std::unique_ptr<Telemetry> m_telemetry;

public:
	Updates();
	void frame_update();
};

}