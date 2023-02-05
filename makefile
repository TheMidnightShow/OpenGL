LIB=-lGL 		\
		-lGLEW 	\
		-lglfw	\

SRC=main.cpp 		\
		window.h 		\
		window.cpp 	\

OpenGL: $(SRC) 
	g++ $(LIB) $(SRC) -o OpenGL
