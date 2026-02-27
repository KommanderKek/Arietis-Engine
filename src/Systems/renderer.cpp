#include "renderer.h"

#include <algorithm>

using namespace Arietis::Systems;

void Renderer::render_windows(std::vector<std::shared_ptr<Core::Window>> windows) {
	if (windows.empty()) {
		return;
	}
	for (std::shared_ptr<Core::Window> window : windows) {
		window->render_menus();
	}
}