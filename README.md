# Texture loading

> [!note]
> - this step require [stb_image](https://github.com/nothings/stb) header

texture loading is much similar to vertex buffer generation we did in the previous branch.
Three things must be done to have a functional texture.

- generate texture and its parameters.
- set an image to the texture buffer.
- bind texture inside window loop.

# Generate texture and parameters
```cpp
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int texture;

/* generate and bind */
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);

/* set texture parameters */
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
```

# Set texture image
```cpp

/* load image data */
int width;
int height;
int channels;

unsigned char* image_data = stbi_load("<path_to_image>", &width, &height, &channels, 0);

/* set image data to image buffer */
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
glGenerateMipmap(GL_TEXTURE_2D);

/* free image data */
stbi_image_free(image_data);

/* unbind */
glBindTexture(GL_TEXTURE_2D, 0);
```

# Use texture
```cpp
/* inside window loop */
{
	glBindTexture(GL_TEXTURE_2D, texture);
}
```

that'll be all for the texture only, you need to adapt your shaders as well if you want to use the texture you want.

### cpp data
```cpp
float vertex_info[]
{
/*  vertex position    texture position*/
	0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,  0.0f, 0.0f,
	0.0f, 0.5f, 0.0f,  0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,  0.0f, 0.0f, 
	0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
	0.0f, 0.5f, 0.0f,  0.0f, 0.0f,
};
```

### vertex shader
```cpp
#version 330 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec2 t_position;

out vec2 texture_position;

void main()
{
	gl_Position = vec4(a_position, 1.0f);
	texture_position = t_position;
}
```

### fragment shader
```cpp
#version 330 core

in vec2 texture_position;
out vec4 fragment;

uniform sampler2D texture_image;

void main()
{
	fragment = texture(texture_image, texture_position);
}
```

### drawing
```cpp
/* window loop */
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glUseProgram(shader_program);

	glBindVertexArray(vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}
```

# Reference

like always, I'll leave a link to LearnOpenGL as it is a really good resource to understand how to work with OpenGL.
Check stb image if you have any doubts about image loading.
Take a look to docs.gl to understand what each gl function does.

[Learn OpenGL | Textures ](https://learnopengl.com/Getting-started/Textures)
[stb_image](https://github.com/nothings/stb)
[docs.gl](https://docs.gl)
