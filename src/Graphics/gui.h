#pragma once

#include "Panel.h"

#include <vector>

class GUI {
private:
	std::vector<Panel> m_panels;

public:
	Panel* create_panel(float x, float y, float width, float height);
};