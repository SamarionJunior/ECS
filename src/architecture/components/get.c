#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include "components.h"
#include "get.h"

// Occurrences getComponentsByProperty(Array *array, int id){

// 	Occurrences occurrences;

// 	occurrences.size = 0;

// 	void* temp = NULL;

// 	for (size_t j = 0; j < lengthArray(array); j++){

// 		temp = (Information*)getArray(array, j);

// 		if(temp == NULL){
// 			break;
// 		}

// 		if(((Id*)(temp))->id != id){
// 			continue;
// 		}

// 		occurrences.size++;

// 		occurrences.array = (occurrences.size == 1) ? 
// 			malloc(sizeof(Occurrence) * occurrences.size) :
// 			realloc(occurrences.array, sizeof(Occurrence) * occurrences.size);

// 		occurrences.array[occurrences.size - 1].component = temp;
// 		occurrences.array[occurrences.size - 1].index = j;

// 	}

// 	return occurrences;
// }

bool getOccurrenceById(Array *array, int id, Occurrence* temporaryOccurrence){

	void* temporaryComponent = NULL;

	for (size_t j = 0; j < lengthArray(array); j++){

 		temporaryComponent = getArray(array, j);

		if(temporaryComponent == NULL){
			continue;
		}

		if((*(Id*)temporaryComponent).id != id){
			continue;
		}

		temporaryOccurrence->component = temporaryComponent;
		temporaryOccurrence->index = j;

		return true;

	}

	return false;
}

void freeComponent(Occurrences* Occurrences){
	if(Occurrences == NULL){
		return;
	}
	// printf("%s %s %d %p\n", __FILE__, __func__, __LINE__, Occurrences->array);
	if(Occurrences->array == NULL){
		return;
	}
	free(Occurrences->array);
	Occurrences->array = NULL;
}

void freeComponents(int size, ...){

	va_list args;

	va_start(args, size);

	for (size_t i = 0; i < size; i++){

		freeComponent(va_arg(args, Occurrences*));

	}

	va_end(args);

}
