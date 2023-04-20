#include <SDL/SDL.h>
#include "entite_secondaire.h"
#include <SDL/SDL_mixer.h>

void initBackground(Image *Backg)
{
	Backg->img= IMG_Load("/home/anwar/Desktop/Game_dev/out.jpg");
	if (Backg->img == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return;
	}
        Backg->pos1.x=0;
	Backg->pos1.y=0;
	Backg->pos2.x=0;
	Backg->pos2.y=0;
	Backg->pos2.w=SCREEN_W;
	Backg->pos2.h=SCREEN_H;
}

void afficher(Image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);
}

void initEnnemi(Ennemi * e){
	e->sprite_sheet= IMG_Load("/home/anwar/Desktop/Game_dev/spritesheet.png");
	e->direction = 3;
	
	e->posScreen.x = 5;
	e->posScreen.y = 170;
	e->posScreen.w = 64;
	e->posScreen.h = 64;
	
	e->posSprite.x = 0;
	e->posSprite.y = 0;
	e->posSprite.w = 64;
	e->posSprite.h = 64;
}

void afficherEnnemi(Ennemi e, SDL_Surface * screen){
	SDL_BlitSurface(e.sprite_sheet, &e.posSprite, screen, &e.posScreen);
}

void animerEnnemi( Ennemi * e){
	e->posSprite.y = e->direction * 64;
	if (e->posSprite.x >= 512){
		e->posSprite.x = 0;
	}
	e->posSprite.x += 64;
}

void move(Ennemi *e) {
    int posmax = 290;
    int posmin = 0;
	if (e->posScreen.x < posmin){
		e->direction = 3;
	}
	if (e->posScreen.x > posmax){
		e->direction = 1;
	}
	
	if (e->direction == 1){
		e->posScreen.x -= 7;
	}
	if (e->direction == 3){
		e->posScreen.x += 7;
	}
}

int collisionBB( Ennemi *p, Ennemi *e){
	int collision;
    if (e->posScreen.x + e->posScreen.w  < p->posScreen.x){
	collision = 0;
    }
    if (e->posScreen.x > p->posScreen.x + p->posScreen.w){
	collision = 0;
    }
    if (e->posScreen.y + e->posScreen.h  < p->posScreen.y){
	collision = 0;
    }
    if (e->posScreen.y  > p->posScreen.y + p->posScreen.h) {
        collision = 0;
    }
    else {
        collision = 1;
    }
    return collision;
}



