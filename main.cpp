#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
  /* initialize glfw library */ 
  if(!glfwInit())
  {
    std::cout << "[!] glfw init failed!" << std::endl;
    return -1;
  }

  /* create a window */
  GLFWwindow* program_window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);

  if(!program_window)
  {
    std::cout << "[!] could not create a window!" << std::endl;
    glfwTerminate();
    return -1;
  }

  /* make an OpenGl context */
  glfwMakeContextCurrent(program_window); 

  /* initialize glew library */
  if(glewInit() != GLEW_OK) 
  { 
    std::cout << "[!] glew init failed!" << std::endl;
    return -1; 
  }

  /* keep window opened */
  while(!glfwWindowShouldClose(program_window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

    glfwPollEvents();
    glfwSwapBuffers(program_window);
  }

  /* destroy window */
  glfwDestroyWindow(program_window);
  glfwTerminate();

  return 0;
}
