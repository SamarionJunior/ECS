#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"
#include "../../../dependencies/my/matrix/full.h"
#include "../../../dependencies/my/matrix/add.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"
#include "../../../dependencies/my/matrix/destroy.h"

char *namesOfSystems[MAX_SYSTEMS] = {
	"Gravity",
	"Collision",
	"Layer",
	"Move"
};