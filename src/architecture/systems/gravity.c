// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #include "systems.h"
// #include "../entities/entities.h"
// #include "../components/components.h"
// #include "../components/get.h"
// #include "../../constants.h"
// #include <stdlib.h>

// #include "../../engine/input.h"

// void gravity();

// static Id* id = NULL;

// static Occurrence occurrencePosition;
// static Occurrence occurrenceSize;

// void gravity(){

//   for(size_t i = 0 ; i < lengthArray(playerArray); i++){
    
//     if((id = (Id*)getArray(playerArray, i)) == NULL){
// 			continue;
// 		}

// 		if(getOccurrenceById(positionArray, id->id, &occurrencePosition) == false){
// 			continue;
// 		}

// 		if(getOccurrenceById(sizeArray, id->id, &occurrenceSize) == false){
// 			continue;
// 		}

//     if(collisionBetween(*((Position*)(occurrencePosition.component)), *((Size*)(occurrenceSize.component))) == true){
//       continue;
//     }

// 		((Position*)(occurrencePosition.component))->current2.y += 0.01f;
		
// 	}
// }

// // 	// ComponentsForGravity* components;

// // 	// for (size_t i = 0; i < lengthRow(&componentsForGravity, 0); i++){

// // 	// 	// printf("\n%d\n", *(int *)getIdInSystem(GRAVITY, i));


// // 	// 	// printf("\noi-2\n");

// // 	// 	// if(!existEntities(0 ,*(int*)(getCell(&componentsForGravity, 0, i)->data))){
// // 	// 	// 	continue;
// // 	// 	// }
		
// // 	// 	components = (ComponentsForGravity *)getCompontFromSystem(GRAVITY, i);
		
// // 	// 	if(!components->collision->collisionDirection[BOTTOM]){
// // 	// 		// // // // printf("\ndsdsdsd\n");
// // 	// 		components->position->current2.y += 300 * delta_time;
// // 	// 	}

// // 	// 	// if(arrayKey[MY_TOP]){
// // 	// 	// 	// // // // printf("\n%p\n", ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity)));
// // 	// 	// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= 300 * delta_time;
// // 	// 	// }

// // 	// }
// // }