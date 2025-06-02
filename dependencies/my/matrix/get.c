#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "get.h"

Data* getCell(Matrix *matrix, size_t row, size_t collum);

Data* getCell(Matrix *matrix, size_t row, size_t collum){

	////////////////////////
	/// VERIFY ARGUMENTS ///
	////////////////////////

	///////////////////////////////////////////////
	/// VERIFY TYPE OF SCENE AND NEW COMPONENTS ///
	///////////////////////////////////////////////

	return &matrix->matrix[row][collum];

}


