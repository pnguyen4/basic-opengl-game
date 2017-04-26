OBJS = main.cpp level.cpp terrain_object.cpp moving_object.cpp

CC = g++

INCLUDE_PATHS = -I/usr/include/ -I/opt/X11/include

LIBRARY_PATHS = -L/usr/lib -L/opt/X11/lib

COMPILER_FLAGS = -w

LINKER_FLAGS = -lglut -lGL

OBJ_NAME = a.out

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATH) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
