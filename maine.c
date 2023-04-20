#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "entite_secondaire.h"

int main(){
    SDL_Surface *screen;
    SDL_Event event;
    int done = 0;
    int vies = 3;

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE );
    if(!screen){
        printf("Failed to create screen: %s\n", SDL_GetError());
        return 1;
    } 
    Image Backg;
    initBackground(&Backg);
    Ennemi p;
    Ennemi enemy;
    initEnnemi(&enemy);
    while(!done){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                done = 1;}}
        move(&enemy);
        animerEnnemi(&enemy);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	afficher(Backg,screen);
        afficherEnnemi(enemy, screen);
	if (collisionBB(&p,&enemy) == 1){
		vies--;
		printf("collision !\n");}
        SDL_Flip(screen);
        SDL_Delay(100);
    } 
    SDL_Quit();
    return 0;
}
