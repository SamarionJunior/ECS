#ifndef UPADTE_H_
#define UPADTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

extern int last_frame_time;
extern float delta_time;

void resetDelay(void);
void delay(int *isPaused);

void update(int *game_is_running);

#endif