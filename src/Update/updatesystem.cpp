#include "updatesystem.h"

UpdateSystem::UpdateSystem() {
	telemetry = std::make_unique<Telemetry>();
}

void UpdateSystem::frame_update() {
	telemetry->telemetry_tick();
}

