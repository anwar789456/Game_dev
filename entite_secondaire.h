#ifndef entite_secondaire_H
#define entite_secondaire_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 350
#define SCREEN_H 300

typedef struct{
	SDL_Surface *sprite_sheet;
	SDL_Rect posScreen;
	SDL_Rect posSprite;
	int direction;
}
Ennemi;

typedef struct{
	SDL_Rect pos1,pos2;
	SDL_Surface *img;
}Image;

void initBackground(Image *Backg);
void afficher(Image p,SDL_Surface *screen);
void initEnnemi(Ennemi * e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void move( Ennemi * e);
int collisionBB( Ennemi *p, Ennemi *e);


#endif

