#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Game.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = project_1

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -o $(OBJ_NAME)

#needed to sudo apt install libsdl2-image-dev

#imgui_impl_sdl.h imgui_impl_opengl3.h
interface: interface.cpp
	g++ interface.cpp -lSDL2 -lSDL2_image -o interface