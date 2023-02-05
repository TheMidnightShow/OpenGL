#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <functional>

#ifndef WINDOW
#define WINDOW

class Window
{
  public:
    Window(); ~Window();

    void start();
    void start(std::function<void()> start_function);

    void update();
    void update(std::function<void()> update_function);

  private:
    GLFWwindow* id;
};

#endif
