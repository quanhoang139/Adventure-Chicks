#include "Window.h"

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    Window window;
    window.init();
    window.run();
    window.close();
    return 0;
}
