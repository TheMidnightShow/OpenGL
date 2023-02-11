LIB=-lGL 		\
		-lGLEW 	\
		-lglfw	\
 
FILE=main.cpp 	\
		window.cpp 	\
	 	window.h 		\
		shader.cpp 	\
		shader.h 		\
		texture.cpp	\
		texture.h 	\

OpenGL : $(FILE) 
	g++ $(LIB) $(FILE) -o OpenGL
