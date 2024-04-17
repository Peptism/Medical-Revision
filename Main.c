#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) {
    printf("Hello, world");
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // FILE *file = fopen("src/data/Data.json", 'r');

    SDL_Window *window = SDL_CreateWindow("ain't no way", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
        if (NULL == window) {
            printf("Could not create window: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL) {
            printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

    SDL_Surface* shapeSurface = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0);
        if (shapeSurface == NULL) {
            printf("SDL_Surface error: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

    SDL_FreeSurface(shapeSurface);
    SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    // SDL_Delay(1000);
    SDL_DestroyRenderer(renderer);

    SDL_Event windowEvent;

    while (1) {
        if (SDL_PollEvent(&windowEvent)) {

            if (SDL_QUIT == windowEvent.type) {break;}

        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    

    return 0;
}