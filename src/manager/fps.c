#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>
#include <sys/time.h>

#include "fps.h"

void startFrameCount();
void endFrameCount();
void calculateFramesNumber();
void resertFrameVariables();

static long int count = 0;

static long int media = 0;

static long int secunds = 0;

static long int countSecunds = 0.0;

static struct timeval end, start;

void resertFrameVariables(){
	count = 0;
	media = 0;
	secunds = 0;
	countSecunds = 0.0;
}

void startFrameCount(){
	gettimeofday(&start, NULL);
}

void endFrameCount(){
	gettimeofday(&end, NULL);
}

void calculateFramesNumber(){

	if(end.tv_usec < start.tv_usec){
		long int q = 999999 - start.tv_usec;
		long int w = end.tv_usec + q;
		countSecunds += w;
	}else{
		countSecunds += (end.tv_usec - start.tv_usec);
	}

	count++;

	if (countSecunds > 999999){
		
		secunds++;

		media += count;

		// printf("secunds: %lu | microsecunds: %lu | FPS: %lu | media: %lu\n", secunds, countSecunds, count, (media / secunds));
		printf("%d - FPS: %lu | media: %lu\n", rand()%10, count, (media / secunds));
		// printf("Entities: %d\n", lengthArray(entityArray));
		// if(vectorPosition.data != NULL){
			// printf("\n--> lengthCollumnPosition: %d\n", vectorPosition.columnLength);
		// }
		// printf("start\t %lu us\n", start.tv_usec);
		// printf("stop\t %lu us\n", stop.tv_usec);
		countSecunds = 0.0;
		count = 0;
	}

}