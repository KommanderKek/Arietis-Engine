#include "./Core/application.h"

#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
    Application app = Application();
    app.initialize();
    app.run();

    return 0;
}