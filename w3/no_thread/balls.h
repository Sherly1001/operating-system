#ifndef _BALLS_H_
#define _BALLS_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define SW 640
#define SH 480
#define SK 10
#define BZ 10

typedef struct coord {
	int x, y;
} coord_t;

typedef struct Ball {
	coord_t cur;
	coord_t next;
	uint32_t color;
} Ball_t;

void initBall(Ball_t *ball);
void ballMove(Ball_t *ball);
void renderBall(SDL_Renderer *rend, const Ball_t *ball);

void pickColor(SDL_Renderer *rend, uint32_t c);

#endif