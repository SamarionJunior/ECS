#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include "components.h"
#include "get.h"

int getIdByComponent(void* temporaryComponent){
	return (*(Id*)temporaryComponent).id;
}

int getIdByOccurrence(Occurrence temporaryComponent){
	return (*(Id*)temporaryComponent.component).id;
}

bool getComponentById(Array array, int id, void** temporaryComponent){
	void* auxiliaryComponent = NULL;
	for (size_t j = 0; j < lengthArray(array); j++){
 		auxiliaryComponent = getArray(array, j);
		if(auxiliaryComponent == NULL){
			continue;
		}
		if(getIdByComponent(auxiliaryComponent) != id){
			continue;
		}
		*temporaryComponent = auxiliaryComponent;
		return true;
	}
	return false;
}

bool interationComponent(int id, int size, va_list args){
	va_list copyArgs;
	va_copy(copyArgs, args);
	for (size_t i = 0; i < (size/2); i++){
		Array array = va_arg(copyArgs, Array);
		void** component = va_arg(copyArgs, void**);
		if(getComponentById(array, id, component) == false){
			va_end(copyArgs);
			return false;
		}
	}
	va_end(copyArgs);
	return true;
}

bool getComponentsById(int id, int size, ...){
	if(size % 2 != 0){
		return false;
	}
	va_list args;
	va_start(args, size);
	if(interationComponent(id, size, args) == false){
		va_end(args);
		return false;
	}
	va_end(args);
	return true;
}

bool getComponentByIndex(Array temporaryArray, int index, void** temporaryComponent){
	void* auxiliaryComponent = NULL;
	auxiliaryComponent = getArray(temporaryArray, index);
	if(auxiliaryComponent == NULL){
		return false;
	}
	*temporaryComponent = auxiliaryComponent;
	return true;
}

bool getIdByIndex(Array temporaryArray, int index, Id* temporaryId){
	void* auxiliaryComponent;
	if(getComponentByIndex(temporaryArray, index, &auxiliaryComponent) == false){
		return false;
	}
	int auxiliaryId = getIdByComponent(auxiliaryComponent);
	temporaryId->id = auxiliaryId;
	return true;
}

bool getComponentsByIndex(Array temporaryArray, int index, int size, ...){
	if(size % 2 != 0){
		return false;
	}
	void* temporaryComponent = NULL;
	Id temporaryId;
	if(getIdByIndex(temporaryArray, index, &temporaryId) == false){
		return false;
	}
	va_list args;
	va_start(args, size);
	if(interationComponent(temporaryId.id, size, args) == false){
		va_end(args);
		return false;
	}
	va_end(args);
	return true;
}

bool getOccurrenceById(Array array, int id, Occurrence* temporaryOccurrence){
	void* temporaryComponent = NULL;
	for (size_t j = 0; j < lengthArray(array); j++){
 		temporaryComponent = getArray(array, j);
		if(temporaryComponent == NULL){
			continue;
		}
		if(getIdByComponent(temporaryComponent) != id){
			continue;
		}
		temporaryOccurrence->component = temporaryComponent;
		temporaryOccurrence->index = j;
		return true;
	}
	return false;
}

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
