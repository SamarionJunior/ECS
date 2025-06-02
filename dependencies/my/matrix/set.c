#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "set.h"

void setCell(Matrix *matrix, size_t row, size_t collum, Data newData);

void setCell(Matrix *matrix, size_t row, size_t collum, Data newData){

	////////////////////////
	/// VERIFY ARGUMENTS ///
	////////////////////////

	///////////////////////////////////////////////
	/// VERIFY TYPE OF SCENE AND NEW COMPONENTS ///
	///////////////////////////////////////////////

	free(matrix->matrix[row][collum].data);

	matrix->matrix[row][collum] = newData;

}


