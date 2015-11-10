#include <stdio.h>
#include <time.h>
#include "include/SDL2/SDL.h"

int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	fprintf(stderr, "Initialization Error: %s", SDL_GetError());
    
    SDL_Window* win = SDL_CreateWindow("Benchmark", 100, 100, 640, 480,
        SDL_WINDOW_SHOWN);
    
    SDL_Surface* sur = SDL_GetWindowSurface(win);

    clock_t start, stop;

    start = clock();
    int i;
    for(i = 0; i < 2000; i++) {
        SDL_Surface* bmp;
        if(i%2 == 0)
            bmp = SDL_LoadBMP("sample.bmp");
        else
            bmp = SDL_LoadBMP("firefox.bmp");

        SDL_UpdateWindowSurface(win);

        SDL_BlitSurface(bmp, NULL, sur, NULL);

        SDL_FreeSurface(bmp);
        bmp = NULL;
    }
    stop = clock();

    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("%f", elapsed);

    SDL_DestroyWindow(win);

    SDL_Quit();
    
    return 0;   
}
