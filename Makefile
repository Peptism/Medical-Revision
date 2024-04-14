all:
	gcc -I src/include -L src/lib -o Main Main.c -lmingw32 -lSDL2main -lSDL2
	