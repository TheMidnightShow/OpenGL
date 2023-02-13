
# GLSL

The OpenGL shading language is used to create our shader programs in a C fashioned sintax to make things a bit easier.

this section will have an `example.shader` file used to create a boring triangle with multiple colors.

the structure is really simple

- declare a glsl version through directive \#version
- declare any variable you need for your program
- insert program logic inside main function

```cpp
#version 460 core
layout (location = 0) in vec3 a_position;

void main()
{
	gl_Position = vec4(a_position, 1.0f);
}
```

# Functions

```cpp
void my_function(in int input, out int output, inout int inoutput)
{
	input = 0;
	output = input * inoutput;
	inoutput = 30;
}

void main()
{
	int input    = 10;
	int output   = 2;
	int inoutput = 40;

	my_function(input, output, inoutput);
}
```

the result of that function would be 

- input = 10;
- output = 400;
- inoutput = 30;

as you can see, input does not change, since it was declared as an  `in` value, output and inoutput are allowed to change.

glsl also supports return values like C, but this approach allows multiple return values (do not like it personally, but it is good to know it exists).

```cpp
vec3 foo(vec3 vector)
{
	vec3 res = vector + vec3(1.0f);
	return res;
}
```

# Data types
```c++
void main()
{
	int x;
	float y;
	
	vec3 triple_vector;
	mat4 matrix_variable;
}
```

almost same data types as C while also adding new types like vec (vec2, vec3, vec4) and matrix (mat2, mat3, mat4), special types that will help us working with shaders.

# Uniforms
uniforms allow us to put data from our C++ code into shaders, data that we will be able to modify inside the shaders later.

### C++ code
```c++
/* while loop */
{
	/* bind program */
	glUseProgram(shader_program);

	/* create and put data into uniform */
	float data[3] = { 0.0f, 1.0f, 3.0f };

	int location = glGetUniformLocation(shader_program, "my_uniform");
	glUniform3f(location, data[0], data[1], data[2]);

	// . . .
}
```

### GLSL code
```c++
#version 460 core

uniform vec3 my_uniform;

void main()
{
	/* code logic */
}
```

we are simply setting some shader data outside the shader, this is a really usefull in case we required some shared data inside our C++ program and our shader programs.

# Resources

reading both Khronos wiki and docs.gl in order to understand in depth how versatily shaders can be.

[Khronos group wiki](https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language)
[docs.gl](https://docs.gl/)