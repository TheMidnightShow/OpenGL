#include "window.h"

void start_function()
{
  std::cout << "hello world!" << std::endl;
}
 
int main()
{
  Window example_window;

  example_window.start(start_function);
  example_window.update();

  return 0;
}
