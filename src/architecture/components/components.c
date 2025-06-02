#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "../../constants.h"
#include "../../../dependencies/my/matrix/get.h"
#include "../../../dependencies/my/matrix/destroy.h"

Color black = {0, 0, 0, 255};

char *namesOfCompenents[QTD_TYPE_COMPONENTS] = {
	"Information",
	"Position",
	"Direction",
	"Velocity",
	"Acceleration",
	"Size",
	"Color",
	"Collider",
	"Layer"
};

Matrix information;
Matrix position;
Matrix direction;
Matrix velocity;
Matrix acceleration;
Matrix size;
Matrix color;
Matrix collider;
Matrix layer;

void destroyComponents();
int getDirectionCollision(int scene, int index, Coordenate direction);

int getDirectionCollision(int scene, int index, Coordenate direction){
	return (*(Collider*)(getCell(&collider, scene, index))).collisionDirection[direction];
}

void destroyComponents(){
	destroyMatrix(&information);
	destroyMatrix(&position);
	destroyMatrix(&direction);
	destroyMatrix(&velocity);
	destroyMatrix(&acceleration);
	destroyMatrix(&size);
	destroyMatrix(&color);
	destroyMatrix(&collider);
	destroyMatrix(&layer);
}