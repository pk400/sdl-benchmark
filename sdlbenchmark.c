#include <stdio.h>
#include <time.h>
#include "SDL2/SDL.h"

int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        printf("Initialization Error: %s", SDL_GetError());
    
    SDL_Window* win = SDL_CreateWindow("Benchmark", 100, 100, 640, 480,
        SDL_WINDOW_SHOWN);
    if(!win)
        printf("Window Error: %s", SDL_GetError());
    
    SDL_Surface* sur = SDL_GetWindowSurface(win);
    if(!sur)
        printf("Surface Error: %s", SDL_GetError());
    


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
    printf("%f\n", elapsed);

    SDL_DestroyWindow(win);

    /*
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
*/
    SDL_Quit();
    
    return 0;   
}
