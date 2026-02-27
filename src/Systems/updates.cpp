#include "updates.h"

using namespace Arietis::Systems;

Updates::Updates() {
	m_telemetry = std::make_unique<Telemetry>();
}

void Updates::frame_update() {
	m_telemetry->telemetry_tick();
}