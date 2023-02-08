#include "window.h"
#include "shader.h"

unsigned int vertex_array;
unsigned int vertex_buffer;

int main()
{
  Window example_window;

  Shader shader_program("./example.shader");

  example_window.start([&]()
  {
    /* create data for vertex */
    float data[]
    {
      -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.0f,  0.5f, 0.0f,
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);

    /* unbind */
    glBindVertexArray(0);

  });

  example_window.update([&]()
  {
    shader_program.use();
    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
  });

  return 0;
}
