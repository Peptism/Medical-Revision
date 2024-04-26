#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400

SDL_Window* InitialiseSDL() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initialising SDL: ", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow("ain't no way", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window) {
        printf("Error creating window: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}

SDL_Renderer* CreateRenderer(SDL_Window *window) {

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Error Creating renderer: %s\n", SDL_GetError());
        return NULL;
    }
    return renderer;
}

void Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void EventsHandler() {

    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent)) {

        if (windowEvent.type == SDL_QUIT) {
            exit(0);
        }

    }
}

void CleanUp(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void UpdateSpeed(int i) {
    printf("%d", i);
    i++;
}

int main(int argc, char* args[]) {
    printf("Hello, world");


    SDL_Window *window = InitialiseSDL();
    if (window == NULL) {
        return 1;
    }

    SDL_Renderer *renderer = CreateRenderer(window);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        return 1;
    }
    int i = 0;

    while (1) {
        EventsHandler();
        Render(renderer);
    }

    CleanUp(renderer, window);

    return 0;
}