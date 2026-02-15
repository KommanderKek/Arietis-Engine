#pragma once

#include "windowrenderer.h"

#include <vector>
#include <memory>

class RenderSystem {
private:

public:
	void render_windows(std::vector<std::shared_ptr<WindowRenderer>> windows);
};