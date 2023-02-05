# Window Abstraction

the basic window example was good and all, but I with all honesty, an abstraction of it would not hurt anybody, would it?

this example is divided in three parts.

- window.cpp
- window.h 
- main.cpp

this abstraction is created so you can care about what the program should do at start, and what is suppossed to do every time it updates window data.

### example
```cpp
#include <iostream>
#include "window.h"

void start_function()
{
	std::cout << "hello world!" << std::endl;
}

int main()
{
	Window example;
	
	example.start(start_function);
	example.update();
	return 0;
}
```

this example should then create a black screen and send a console message.