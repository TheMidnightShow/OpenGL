# Graphics Pipeline

data in OpenGL is inside a 3D space, but displayed on a 2D screen.

how this data is transformed from 3D to 2D is managed by a graphics pipeline, where it should go through some steps.

- vertex shader
- shape assembly
- geometry shader
- rasterization
- fragment shader
- test and blending

we will mainly care about two of these right now, vertex and fragment shaders

### Vertex Shaders
- [ ] take some input data and transform it. also pass data to the fragment shader.
you can understand vertex shaders as a process to transform data into visuals.

### Fragment Shaders
is designated to give the pixels its final color, get some data from vertex shaders and can change it internally.
visual data given by the vertex shaders comes to life once fragment shaders give color to those lifeless figures in your screen.

# how do I give data to shaders?

shaders can get data through little programs created for your gpu inside our program.

we will divide this problem in steps.

### create some data to use.
```cpp

float data[]
{/* x_axis, y_axis, z_axis */
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};
```

### give the data to OpenGL.
```cpp
/* where vertex data will be stored */
unsigned int vertex_array;
unsigned int vertex_buffer;

/* generate arrays and buffers */
glGenVertexArrays(1, &vertex_array);
glGenBuffers(1, &vertex_object);

/* bind buffers to store data */
glBindVertexArray(vertex_array);
glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

/* put data inside buffer */
glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

/* specify data layout */
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
glEnableVertexAttribArray(0);

/* unbind */
glBindVertexArray(0);
```

### create our shader program.
```cpp
/* create vertex shader code */
const char* vertex_shader = 
	"#version 330 core\n"
	"layout (location = 0) in vec3 a_position;\n"
	"void main()\n"
	"{\n"
	"gl_Position = vec4(a_position, 1.0f);\n"
	"}\n";
	
/* create fragment shader code */
const char* fragment_shader =	
	"#version 330 core\n"
	"out vec4 fragment_position;\n"
	"void main()\n"
	"{\n"
	"fragment_position = vec4(0.0f, 1.0f, 0.5f, 1.0f);\n"
	"}\n";

/* compile shaders */
unsigned int vertex_program = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertex_program, 1, &vertex_shader, NULL);
glCompileShader(vertex_program);

unsigned int fragment_program = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragment_program, 1, &fragment_shader, NULL);
glCompileShader(fragment_program);

/* link program */
unsigned int shader_program = glCreateProgram();
glAttachShader(shader_program, vertex_program);
glAttachShader(shader_program, fragment_program);
glLinkProgram(shader_program);

/* delete shaders */
glDeleteShader(vertex_program);
glDeleteShader(fragment_program);
```

### render to our screen.
```cpp
/* inside your window update loop */
{
	/* use shader program */
	glUseProgram(shader_program);
	
	/* bind vertex and draw */
	glBindVertexArray(vertex_buffer);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	/* unbind */
	glUseProgram(0);
	glBindVertexArray(0);
}
```

# notes
this is just an explanation on how it is supposed to work, not how is supposed to be implemented.
this branch will get three extra files.

- shader.cpp
- shader.h
- triangle.shader

which will offer a personal preference to implement shader loading.

# references
I will leave a link to openGL functions, so you can check what is OpenGL askin for in every step we went through.
And also a link to LearnOpenGL to get a better perspective of this topic.

[docs.gl](https://docs.gl/)
[LearnOpenGL | hello triangle](https://learnopengl.com/Getting-started/Hello-Triangle)
