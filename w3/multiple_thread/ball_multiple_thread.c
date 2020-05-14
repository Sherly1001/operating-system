#include <SDL2/SDL.h>
#include <pthread.h>
#include "thpool.h"
#include <stdlib.h>
#include <time.h>
#include "balls.h"

int main(int ag, char **av) {
    srand(time(NULL));

    int n = 10;
    if (ag > 1) n = atoi(av[1]);
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *wind = SDL_CreateWindow("Balls with n thread", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SW, SH, SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    threadpool thpool = thpool_init(n);
    Ball_t *balls = malloc(sizeof(*balls) * n);
    for (int i = 0; i < n; ++i) {
        initBall(balls + i);
    }

    SDL_Event e;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = 0;
        }

        pickColor(rend, 0x000000ff);
        SDL_RenderClear(rend);
        
        for (int i = 0; i < n; ++i) {
            thpool_add_work(thpool, (void*)ballMove, balls + i);
        }

        for (int i = 0; i < n; ++i) {
            renderBall(rend, balls + i);
        }

        SDL_RenderPresent(rend);
    }

    thpool_destroy(thpool);

    free(balls);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
    SDL_Quit();
}