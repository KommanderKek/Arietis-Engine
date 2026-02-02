#include "rendersystem.h"

#include <algorithm>

void RenderSystem::add_window(std::shared_ptr<WindowRenderer> window) {
	m_windows.push_back(window);
}

void RenderSystem::remove_window(std::shared_ptr<WindowRenderer> window) {
	std::vector<std::shared_ptr<WindowRenderer>>::iterator it = std::find(m_windows.begin(), m_windows.end(), window);
	if (it == m_windows.end()) {
		return;
	}
	m_windows.erase(it);
}

void RenderSystem::render_windows() {
	if (m_windows.empty()) {
		return;
	}
	for (std::shared_ptr<WindowRenderer> window : m_windows) {
		window->render_guis();
	}
}