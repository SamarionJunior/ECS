#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "entities.h"
#include "../../constants.h"

int idcount = 0;

Entity entityDefualt = (Entity){.index = &(int){-1}};