#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) {
    printf("Hello, world");
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // Initialize SDL_ttf
    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

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

    // Load font
    TTF_Font* font = TTF_OpenFont("src/fonts/Arial/arial.ttf", 28); // Replace "arial.ttf" with your font file path
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Color textColor = {255, 255, 255, 255}; // White color

    // Render text to surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello, SDL_ttf!", textColor);
    if (textSurface == NULL) {
        printf("Failed to render text surface: %s\n", TTF_GetError());
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("Failed to create texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
    SDL_RenderClear(renderer);

    // Render text texture
    SDL_Rect dstRect = {100, 100, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &dstRect);

    // Update screen
    SDL_RenderPresent(renderer);

    SDL_Event windowEvent;

    while (1) {
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
        }
    }

    // Cleanup
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
