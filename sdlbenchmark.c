#include <stdio.h>
#include <time.h>
#include "SDL2/SDL.h"

int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        printf("Error: %s", SDL_GetError());
    
    SDL_Window* win = SDL_CreateWindow("Benchmark", 100, 100, 640, 480,
        SDL_WINDOW_SHOWN);
    
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    clock_t start, stop;

    start = clock();
    for(int i = 0; i < 200; i++) {
        SDL_Surface* bmp = SDL_LoadBMP("firefox.bmp");
        
        SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
        SDL_FreeSurface(bmp);

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
    }
    stop = clock();

    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC*10;
    printf("%.4f\n", elapsed);

    SDL_Quit();
    
    return 0;   
}