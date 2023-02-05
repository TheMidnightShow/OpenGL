# OpenGL notes

this is intented for personal use, as a guide and reference on how to use the OpenGL implementation, where I put some explanation of a certain topic and then put respective C++ files to see a real implementation.

That said, lets see which tools are necessary in order to learn OpenGL.

- [glfw](https://www.glfw.org/) for window creation and input handling
- [glew](https://glew.sourceforge.net/) as our OpenGL function wrapper
- [glm](https://github.com/g-truc/glm) to make necessary graphic math (optional)
- patience 

their respective pages introduce you on how to install the libraries on your system, so they got us covered.

# hello window

tools ready, get your editor of preference to get started.

in order to make a window using GLFW, we need to complete just five simple steps.

### initialize glfw 
```cpp
if(!glfwInit())
{
	std::cout << "[!] glfw init failed!" << std::endl;
	return -1;	
}
```

### create a window and valid OpenGL context
```cpp
GLFWwindow* program_window{ glfwCreateWindow(800, 600, "opengl", NULL, NULL) };

if(!program_window)
{
	std::cout << "[!] could not create a window!";
	return -1;
}

glfwMakeContextCurrent(program_window);
```

### initialize glew
```cpp
if(glewInit() != GLEW_OK)
{
	std::cout << "[!] glew init failed!" << std::endl;
	return -1;
}
```

### make a window loop
```cpp
while(!glfwWindowShouldClose(program_window))
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glfwPollEvents();
	glfwSwapBuffers(program_window);
}
```

### create a window destroyer
```cpp
glfwDestroyWindow(program_window);
glfwTerminate();
```

once all of that is done, you should compile and get an exciting black screen that does nothing.

check [main.cpp](./main.cpp) to see the final result.

# references

this notes are really vague and does not explain a lot of what is going on, so I will leave some links that explain more details.

[LearnOpenGL | Hello Window](https://learnopengl.com/Getting-started/Hello-Window)
[The Cherno | setting up openGL and creating a window in C++](https://youtu.be/OR4fNpBjmq8)
