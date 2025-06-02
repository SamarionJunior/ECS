#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#pragma once

#define ID_INIT -1

#define RUN     0
#define PAUSE   1
#define RESTART 2
#define CLOSE   3
#define RESUME  4

#define ERROR 1
#define SUCESS 0

#define VOID 0

#define SPRITE 32

#define COL 12
#define ROW 12
#define SPACE 2

// #define WINDOW_WIDTH 480
// #define WINDOW_HEIGHT 480

#define WINDOW_WIDTH (COL*SPRITE)+(SPACE*SPRITE)
#define WINDOW_HEIGHT (ROW*SPRITE)+(SPACE*SPRITE)
// #define WINDOW_WIDTH 800
// #define WINDOW_HEIGHT 600

#define FPS 60
#define FRAME_TARGET_TIME (1000/FPS)

extern int globalCount;

extern int score;

#endif