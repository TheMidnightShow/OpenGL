#shader vertex 
#version 460 core

layout (location = 0) in vec3 position_a;

out vec3 col;
out vec3 pos;

uniform vec3 colors;

void main()
{
  col = colors;
  pos = position_a;

  float position_x = position_a.x + sin(colors.x);
  float position_y = position_a.y + cos(colors.y);
  float position_z = position_a.z;

  vec3 position_final = vec3(position_x, position_y, position_z);

  gl_Position = vec4(position_a, 1.0f);
}

#shader fragment 
#version 460 core

in vec3 pos;
in vec3 col;

out vec4 fragment_color;

void main()
{
  float fragment_x = pos.z * sin(col.x) + 0.4f;
  float fragment_y = pos.y * cos(col.y) + 0.2f;
  float fragment_z = pos.x * sin(col.z) + 0.4f;

  vec3 final_color = vec3(fragment_x, fragment_y, fragment_z);

  fragment_color = vec4(final_color, 1.0f); 
}
