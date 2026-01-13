#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
public:
    GLFWwindow* window;
    Window(int width, int height, const char* title);
    ~Window();
    bool shouldClose();
    void swapBuffers();
    void pollEvents();
};

#endif
