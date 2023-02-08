#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <fstream>
#include <iostream>

#ifndef SHADER

class Shader
{
  public:
    Shader(const char* path); ~Shader();
    void use();
    void bind_uniform(const char* location, glm::vec3 value);
    void bind_uniform(const char* location, glm::mat4 value);

  private:
    unsigned int id;

    void                      link_program(unsigned int vertex_program, unsigned int fragment_program);
    unsigned int              make_shader(const char* shader_program, const int type);
    std::vector<std::string>  read_file(const char* path);
};

#define SHADER

#endif
