OBJS = main.c

CC = gcc

CFLAGS = -w `sdl2-config --cflags`

LINKER = `sdl2-config --libs` -lSDL2_image

OBJ_NAME = game.run

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER) -o $(OBJ_NAME)

