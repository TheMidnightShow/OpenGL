#include "window.h"
#include "shader.h"
#include "texture.h"

unsigned int vertex_array;
unsigned int vertex_buffer;

int main()
{
  Window example_window;

  Shader shader_program("./example.shader");
  Texture shader_texture("./wood.jpg");

  example_window.start([&]()
  {
    /* create data for vertex */
    float data[]
    {
    /* vertex position    texture position*/
      0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
      0.5f, 0.0f, 0.0f,   1.0f, 0.0f,
      0.0f, 0.5f, 0.0f,   0.0f, 1.0f,

      0.5f, 0.0f, 0.0f,   1.0f, 0.0f,
      0.5f, 0.5f, 0.0f,   1.0f, 1.0f,
      0.0f, 0.5f, 0.0f,   0.0f, 1.0f,
    };

    /* generate arrays and buffers */
    glGenVertexArrays(1, &vertex_array);
    glGenBuffers(1, &vertex_buffer);

    /* bind buffers to store data */
    glBindVertexArray(vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array);

    /* store data in buffer */
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    /* specify data layout */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    /* unbind */
    glBindVertexArray(0);

  });

  example_window.update([&]()
  {
    shader_texture.use();
    shader_program.use();
    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
  });

  return 0;
}
