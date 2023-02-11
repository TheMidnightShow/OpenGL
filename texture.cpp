#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "texture.h"

Texture::Texture(const char* path)
{
  /* generate and bind texture */
  glGenTextures(1, &this -> id);
  glBindTexture(GL_TEXTURE_2D, this -> id);

  /* set texutre data */
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  /* load image data */
  int widht;
  int height;
  int channels;

  unsigned char* image_data = stbi_load(path, &widht, &height, &channels, 0);

  /* set loaded data into texture buffer */
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widht, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
  glGenerateMipmap(GL_TEXTURE_2D);

  /* free data and unbindf */
  stbi_image_free(image_data);
  glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() = default;

void Texture::use()
{
  glBindTexture(GL_TEXTURE_2D, this -> id);
}
