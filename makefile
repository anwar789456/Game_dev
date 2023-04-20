prog:maine.o entite.o 
	gcc maine.o entite.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
maine.o:maine.c
	gcc -c maine.c -g
entite.o:entite.c
	gcc -c entite.c -g

