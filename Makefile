OBJS = main.c

CC = gcc

CFLAGS = -w `pkg-config --cflags sdl2`

LINKER = `pkg-config --libs sdl2`

OBJ_NAME = game.run

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER) -o $(OBJ_NAME)

