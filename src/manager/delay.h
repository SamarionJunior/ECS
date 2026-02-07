#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../constants.h"

extern int last_frame_time;
extern double delta_time;

void resetDelay();
void delay(int *isPaused);

#endif