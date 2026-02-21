#include "application.h"

int main(int argc, char* argv[])
{
    Application app;
    app.init();
    app.start();
    app.deinit();

    return 0;
}