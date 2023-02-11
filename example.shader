#shader vertex 
#version 330 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec2 t_position;

out vec2 texture_location;

void main()
{
  gl_Position = vec4(a_position, 1.0f);
  texture_location = t_position;
}

#shader fragment 
#version 330 core

in  vec2 texture_location;
out vec4 fragment_color;
uniform sampler2D fragment_texture;

void main()
{
  fragment_color = texture(fragment_texture, texture_location) * vec4(0.8f, 0.3f, 0.0f, 1.0f); 
}
