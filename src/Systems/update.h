#pragma once

#include "telemetry.h"

#include <memory>

namespace Arietis::Systems {
	class Update {
	private:
		std::unique_ptr<Telemetry> m_telemetry;

	public:
		Update();
		void frame_update();
	};
}