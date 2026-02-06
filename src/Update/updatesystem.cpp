#include "updatesystem.h"

UpdateSystem::UpdateSystem() {
	telemetry = std::make_unique<Telemetry>();
}

void UpdateSystem::add_window(std::shared_ptr<WindowRenderer> window) {
	m_windows.push_back(window);
}

void UpdateSystem::remove_window(std::shared_ptr<WindowRenderer> window) {
	std::vector<std::shared_ptr<WindowRenderer>>::iterator it = std::find(m_windows.begin(), m_windows.end(), window);
	if (it == m_windows.end()) {
		return;
	}
	m_windows.erase(it);
}

void UpdateSystem::frame_update() {
	telemetry->telemetry_tick();
}