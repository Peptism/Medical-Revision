#include <stdio.h>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 400;

int main( int argc, char* args[] ) {
    
    //The window we'll be rendering to
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("ain't no way", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    if (NULL == window) {
        printf("Could not create window: ");
        return 1;
    }

    SDL_Event windowEvent;
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    while (1) {

        if (SDL_PollEvent(&windowEvent)) {

            if (SDL_QUIT == windowEvent.type) {break;}

        }
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();
    

    return 0;
}