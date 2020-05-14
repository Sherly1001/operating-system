#include "balls.h"

void pickColor(SDL_Renderer *rend, uint32_t c) {
    SDL_SetRenderDrawColor(rend, (c & 0xff000000) >> 24, (c & 0x00ff0000) >> 16, (c & 0x0000ff00) >> 8, c & 0x000000ff);
}

void initBall(Ball_t *ball) {
    ball->cur.x = rand() % (SW - BZ) + BZ;
    ball->cur.y = rand() % (SH - BZ) + BZ;
    ball->next.x = (rand() % SK + 1) * (rand() & 1 ? -1 : 1);
    ball->next.y = (rand() % SK + 1) * (rand() & 1 ? -1 : 1);
    ball->color = (rand() & 0xff) << 24 | (rand() & 0xff) << 16 | (rand() & 0xff) << 8 | (rand() & 0xff);
    // printf("%x\n", ball->color);
}

void ballMove(Ball_t *ball) {
    if (ball->cur.x + ball->next.x + BZ > SW || ball->cur.x + ball->next.x - BZ < 0) ball->next.x *= -1;
    else ball->cur.x += ball->next.x;
    if (ball->cur.y + ball->next.y + BZ > SH || ball->cur.y + ball->next.y - BZ < 0) ball->next.y *= -1;
    else ball->cur.y += ball->next.y;
}

void renderBall(SDL_Renderer *rend, const Ball_t *ball) {
    pickColor(rend, ball->color);
    for (int i = 0, j = 0; i <= BZ; ++i) {
        j = SDL_sqrt(BZ * BZ - i * i);
        SDL_RenderDrawLine(rend, ball->cur.x - i, ball->cur.y - j, ball->cur.x - i, ball->cur.y + j);
        SDL_RenderDrawLine(rend, ball->cur.x + i, ball->cur.y - j, ball->cur.x + i, ball->cur.y + j);
    }
}