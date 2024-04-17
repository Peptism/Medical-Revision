all:
	gcc -I src/sdl/include -L src/sdl/lib -o Main Main.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
	