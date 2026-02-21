#pragma once

#include "Core/window.h"

#include <vector>
#include <memory>

namespace Arietis::Systems {
	class Render {
	private:

	public:
		void render_windows(std::vector<std::shared_ptr<Core::Window>> windows);
	};
}