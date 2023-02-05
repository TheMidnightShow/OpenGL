#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
  /* create a window */ 
  if(!glfwInit())
  {
    std::cout << "[!] glfw init failed!" << std::endl;
    return -1;
  }

  /* create an OpenGL context */
  GLFWwindow* program_window = glfwCreateWindow(600, 800, "OpenGL", NULL, NULL);
  glfwMakeContextCurrent(program_window); 

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

    glfwSwapBuffers(program_window);
  }

  /* destroy window */
  glfwDestroyWindow(program_window);
  glfwTerminate();

  return 0;
}
