#include "rendersystem.h"

#include <algorithm>

void RenderSystem::render_windows(std::vector<std::shared_ptr<WindowRenderer>> windows) {
	if (windows.empty()) {
		return;
	}
	for (std::shared_ptr<WindowRenderer> window : windows) {
		window->render_guis();
	}
}