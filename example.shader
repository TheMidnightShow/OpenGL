#shader vertex 
#version 330 core

layout (location = 0) in vec3 a_position;

void main()
{
  gl_Position = vec4(a_position, 1.0f);
}

#shader fragment 
#version 330 core

out vec4 fragment_color;

void main()
{
  fragment_color = vec4(0.4f, 0.0f, 0.5f, 1.0f); 
}
