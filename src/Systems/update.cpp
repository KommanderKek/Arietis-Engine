#include "update.h"

using namespace Arietis::Systems;

Update::Update() {
	m_telemetry = std::make_unique<Telemetry>();
}

void Update::frame_update() {
	m_telemetry->telemetry_tick();
}