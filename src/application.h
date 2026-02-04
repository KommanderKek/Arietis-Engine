#pragma once

#include "./Core/engine.h"

#include <memory>

class Application {
private:
	Engine engine;

public:
	void init();
	void run();
};