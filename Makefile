OBJS = main.c image.c player.c npc.c init.c

CC = gcc

CFLAGS = -w `sdl2-config --cflags`

LINKER = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

OBJ_NAME = game.run

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER) -o $(OBJ_NAME)

