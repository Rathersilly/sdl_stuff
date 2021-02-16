CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2

# OBJS = CApp.cpp CApp_OnInit.o
OBJS = CApp.cpp CApp_OnInit.cpp CApp_OnEvent.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CApp_OnCleanup.cpp
OBJ_NAME = a.out




all:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm OBJ_NAME
