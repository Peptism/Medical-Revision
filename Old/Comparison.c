#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400

SDL_Window* initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow("ain't no way", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}

SDL_Renderer* createRenderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return NULL;
    }

    return renderer;
}

void render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void handleEvents() {
    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent)) {
        if (windowEvent.type == SDL_QUIT) {
            exit(0);
        }
    }
}

void cleanup(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* args[]) {
    printf("Hello, world");

    SDL_Window *window = initSDL();
    if (window == NULL) {
        return 1;
    }

    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        return 1;
    }

    while (1) {
        handleEvents();
        render(renderer);
    }

    cleanup(renderer, window);

    return 0;
}