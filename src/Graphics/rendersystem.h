#pragma once

#include "windowrenderer.h"

#include <vector>
#include <memory>

class RenderSystem {
private:
	std::vector<std::shared_ptr<WindowRenderer>> m_windows;

public:
	void add_window(std::shared_ptr<WindowRenderer> window);
	void remove_window(std::shared_ptr<WindowRenderer> window);
	void render_windows();
};