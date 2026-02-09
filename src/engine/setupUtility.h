#ifndef SETUPUTILITY_H_
#define SETUPUTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

// void addInformationinEntity(size_t k);
// void addPositioninEntity(float x, float y, size_t k);
// void addSizeinEntity(size_t k);
// void addColorinEntity(size_t k);
// void addColliderinEntity(size_t k);
// void addLayerinEntity(size_t k);
// void addPlayerinEntity(size_t k);
// void addCollectibleinEntity(size_t k);
// void addAnchorinEntity(int idParent, size_t k);
void addComponentsinEntity(TemporaryEntity te);
void createKindComponents(TemporaryEntity te);

#endif