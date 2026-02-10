#ifndef SETUPUTILITY_H_
#define SETUPUTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

void addComponentsinEntity(TemporaryEntity te);
void createKindComponents(TemporaryEntity te);

#endif