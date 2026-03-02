#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#pragma once

typedef enum{

  ID_INIT = -1,

  RUN = 0,
  PAUSE = 1,
  RESTART = 2,
  CLOSE = 3,
  RESUME = 4,
  WIN = 5,
  LOSS = 6,

  ERROR = 1,
  SUCESS = 0,

  VOID = 0,

  SPRITE = 32*2,

  // COL_DEFAULT = 20,
  // ROW_DEFAULT = 20,
  COL_DEFAULT = 21,
  ROW_DEFAULT = 8,
  SPACE = 2,
  WALL = 1,
  WALLS = (WALL * 2),

  // WINDOW_WIDTH = (COL_DEFAULT*SPRITE)+(SPACE*SPRITE),
  // WINDOW_HEIGHT = (ROW_DEFAULT*SPRITE)+(SPACE*SPRITE),
  WINDOW_WIDTH = (COL_DEFAULT*SPRITE),
  WINDOW_HEIGHT = (ROW_DEFAULT*SPRITE),
  // WINDOW_WIDTH = 1920,
  // WINDOW_HEIGHT = 1280,

  FPS = 60,
  FRAME_TARGET_TIME = (1000/FPS)

} Config;

extern int game_is_running;

extern int globalCount;

extern int score;

extern char pathMap[];

// extern int COLLUMNS;
// extern int ROWS;

int getCOL();
void setCOL(int newCOL);

int getROW();
void setROW(int newROW);

int getUTILC();
int getUTILR();
int getCOLD();
int getROWD();
int getCRD();

bool getIsEmpty();
void setIsEmpty(int newIsEmpty);

#endif

  // UTILC = (COL - WALLS),
  // UTILR = (ROW - WALLS),
  // COLD = (COL - SPACE),
  // ROWD = (ROW - SPACE),
  // CRD = ((COLD * ROWD) - 1),

// #define ID_INIT -1

// #define RUN     0
// #define PAUSE   1
// #define RESTART 2
// #define CLOSE   3
// #define RESUME  4

// #define ERROR 1
// #define SUCESS 0

// #define VOID 0

// #define SPRITE 32

// // #define COL 12
// // #define ROW 12
// #define COL 6
// #define ROW 6
// #define SPACE 2
// #define WALL 1
// #define WALLS (WALL * 2)
// #define UTILC (COL - WALLS)
// #define UTILR (ROW - WALLS)
// #define COLD (COL - SPACE)
// #define ROWD (ROW - SPACE)
// #define CRD ((COLD * ROWD) - 1)

// // #define WINDOW_WIDTH 480
// // #define WINDOW_HEIGHT 480

// #define WINDOW_WIDTH (COL*SPRITE)+(SPACE*SPRITE)
// #define WINDOW_HEIGHT (ROW*SPRITE)+(SPACE*SPRITE)
// // #define WINDOW_WIDTH 800
// // #define WINDOW_HEIGHT 600

// #define FPS 60
// #define FRAME_TARGET_TIME (1000/FPS)