LIB=-lGL 		\
		-lGLEW 	\
		-lglfw	\

OpenGL: main.cpp
	g++ $(LIB) main.cpp -o OpenGL
