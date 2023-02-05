#include "window.h"

Window::Window()
{
  /* start glfw */
  if(!glfwInit())
  {
    std::cout << "[!window] glfw init failed!" << std::endl;
    return;
  }

  /* create a valid OpenGL contex */
  this -> id = glfwCreateWindow(800, 600, "example", NULL, NULL);
  glfwMakeContextCurrent(id);

  /* enable OpenGL functions */
  if(glewInit() != GLEW_OK)
  {
    std::cout << "[!window] glew init failed!" << std::endl;
    return;
  }
}

Window::~Window() = default;

void Window::start() {}

void Window::start(std::function<void()> start_function)
{
  start_function();
}

void Window::update()
{
  while(!glfwWindowShouldClose(this -> id))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(this -> id);
  }

  glfwDestroyWindow(this -> id);
  glfwTerminate();
}

void Window::update(std::function<void()> update_function)
{
  while(!glfwWindowShouldClose(this -> id))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    update_function();

    glfwPollEvents();
    glfwSwapBuffers(this -> id);
  }

  glfwDestroyWindow(this -> id);
  glfwTerminate();
}
