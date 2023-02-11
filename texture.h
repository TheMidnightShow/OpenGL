#include <GL/glew.h>

#ifndef TEXTURE
#define TEXTURE

class Texture
{
  public:
    Texture(const char* path); ~Texture();
    void use();

  private:
    unsigned int id;
};

#endif
