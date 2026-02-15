#pragma once

#include "./Core/engine.h"

class Application {
private:
	Engine m_engine;

public:
	void init();
	void start();
	void deinit();
};