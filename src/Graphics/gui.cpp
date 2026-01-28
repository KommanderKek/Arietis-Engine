#include "gui.h"

Panel* GUI::create_panel(float x, float y, float width, float height) {
	m_panels.emplace_back(x, y, width, height);
	return &m_panels.back();
}