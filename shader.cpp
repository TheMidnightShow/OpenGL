#include "shader.h"

Shader::Shader(const char* path) 
{
  std::vector<std::string> shaders = this -> read_file(path);

  unsigned int vertex_program = this -> make_shader(shaders[0].c_str(), GL_VERTEX_SHADER);
  unsigned int fragment_program = this -> make_shader(shaders[1].c_str(), GL_FRAGMENT_SHADER);

  this -> link_program(vertex_program, fragment_program); 
}

Shader::~Shader() = default;

void Shader::use()
{
  glUseProgram(this -> id);
}

void Shader::bind_uniform(const char* location, glm::vec3 value)
{
  glUniform3f(glGetUniformLocation(this -> id, location), value.x, value.y, value.z); 
}

void Shader::bind_uniform(const char* location, glm::mat4 value)
{
  glUniformMatrix4fv(glGetUniformLocation(this -> id, location), 1, GL_FALSE, glm::value_ptr(value));
}

std::vector<std::string> Shader::read_file(const char* path)
{
  std::string shaders[2];

  std::ifstream file(path);

  bool type = 0;
  std::string current_line;

  while(std::getline(file, current_line))
  {
    if(current_line.find("#shader vertex") == 0)
    {
      type = 0;
    }
    else if(current_line.find("#shader fragment") == 0)
    {
      type = 1;
    }
    else
    {
      shaders[type].append(current_line + "\n");
    }
  }

  file.close();

  return std::vector<std::string>({shaders[0], shaders[1]});
}

unsigned int Shader::make_shader(const char* shader_source, const int shader_type)
{
  /* create shader */
  unsigned int shader_program = glCreateShader(shader_type);

  glShaderSource(shader_program, 1, &shader_source, NULL);
  glCompileShader(shader_program);

  /* error log */
  int shader_ok;
  char error_log[512];

  glGetShaderiv(shader_program, GL_COMPILE_STATUS, &shader_ok);

  if(!shader_ok)
  {
    glGetShaderInfoLog(shader_program, 512, NULL, error_log);
    std::cout << error_log << std::endl;
  }

  return shader_program;
}

void Shader::link_program(unsigned int vertex_program, unsigned int fragment_program)
{
  this -> id = glCreateProgram();

  glAttachShader(this -> id, vertex_program);
  glAttachShader(this -> id, fragment_program);

  glLinkProgram(this -> id);
}
