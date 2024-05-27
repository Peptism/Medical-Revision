#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400

const SDL_Color textColor = {255, 255, 255, 255}; // White

SDL_Window* InitialiseSDL() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initialising SDL: ", SDL_GetError());
        return NULL;
    }

    if (TTF_Init() != 0) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        SDL_Quit();
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
        printf("Error Creating renderer: %s\n ", SDL_GetError());
        return NULL;
    }
    return renderer;
}

TTF_Font* Write(SDL_Window *window) {

    TTF_Font *fontFace = TTF_OpenFont("src/fonts/Arial/ARIAlbd.ttf", 28);
    if (fontFace == NULL) {
        printf("Error writing to screen: %s\n", TTF_GetError());
        return NULL;
    }
    return fontFace;
}

SDL_Surface* CreateTextSurface(SDL_Window *window, TTF_Font *fontFace) {

    SDL_Surface *textSurface = TTF_RenderText_Blended(fontFace, "Text test.", textColor);
    if (textSurface == NULL) {
        printf("Failed to render text surface: %s\n", TTF_GetError());
        return NULL;
    }
    return textSurface;
}

SDL_Texture* CreateTextTexture(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *textSurface) {

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        return NULL;
    }
    return textTexture;
}

void Render(SDL_Renderer *renderer, SDL_Surface *textSurface, SDL_Texture *textTexture) {
    SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
    SDL_RenderClear(renderer);
    const SDL_Rect dstRect = {100, 100, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &dstRect);
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

void CleanUp(SDL_Renderer *renderer, SDL_Window *window, SDL_Surface *textSurface, TTF_Font *fontFace) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(fontFace);

    TTF_Quit();
    SDL_Quit();
}

void UpdateSpeed(int i) {
    printf("%d", i);
    i++;
}

int main(int argc, char* args[]) {
    printf("Hello, world\n");

    SDL_Window *window = InitialiseSDL();
    if (window == NULL) {
        return 1;
    }

    SDL_Renderer *renderer = CreateRenderer(window);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        return 1;
    }

    TTF_Font *fontFace = Write(window);
    if (fontFace == NULL) {
        return 1;
    }
    
    SDL_Surface *textSurface = CreateTextSurface(window, fontFace);
    if (textSurface == NULL) {
        return 1;
    }

    SDL_Texture *textTexture = CreateTextTexture(window, renderer, textSurface);
    if (textTexture == NULL) {
        return 1;
    }

    while (1) {
        EventsHandler();
        Render(renderer, textSurface, textTexture);
    }

    return 0;
}