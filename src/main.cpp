#include "application.h"

#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
    Application app;
    app.init();
    app.start();
    app.deinit();

    return 0;
}