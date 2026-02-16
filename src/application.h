#pragma once

#include "./Core/engine.h"

class Application {
private:
	Arietis::Core::Engine m_engine;

public:
	void init();
	void start();
	void deinit();
};