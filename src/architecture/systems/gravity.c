#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"
#include <stdlib.h>

#include "../../engine/input.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"
#include "../../../dependencies/my/matrix/full.h"
#include "../../../dependencies/my/matrix/add.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"

// void gravity();

// void gravity(){

// 	// ComponentsForGravity* components;

// 	// for (size_t i = 0; i < lengthRow(&componentsForGravity, 0); i++){

// 	// 	// printf("\n%d\n", *(int *)getIdInSystem(GRAVITY, i));


// 	// 	// printf("\noi-2\n");

// 	// 	// if(!existEntities(0 ,*(int*)(getCell(&componentsForGravity, 0, i)->data))){
// 	// 	// 	continue;
// 	// 	// }
		
// 	// 	components = (ComponentsForGravity *)getCompontFromSystem(GRAVITY, i);
		
// 	// 	if(!components->collision->collisionDirection[BOTTOM]){
// 	// 		// // // // printf("\ndsdsdsd\n");
// 	// 		components->position->current2.y += 300 * delta_time;
// 	// 	}

// 	// 	// if(arrayKey[MY_TOP]){
// 	// 	// 	// // // // printf("\n%p\n", ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity)));
// 	// 	// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= 300 * delta_time;
// 	// 	// }

// 	// }
// }