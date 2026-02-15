#include "updatesystem.h"

UpdateSystem::UpdateSystem() {
	m_telemetry = std::make_unique<Telemetry>();
}

void UpdateSystem::frame_update() {
	m_telemetry->telemetry_tick();
}