#ifndef FPS_H
#define FPS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>
#include <sys/time.h>

void startFrameCount();
void endFrameCount();
void calculateFramesNumber();
void resertFrameVariables();

#endif