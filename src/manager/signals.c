#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <signal.h>

#include "signals.h"

void treatsignal(int signal);
void registerSignal();

void treatsignal(int signal){
	// // // // printf("\nEncerrando\n");
	exit(0);
}

void registerSignal(){
	FILE * filePID = fopen("kill.sh", "w");
	// // // // printf("\nPID = %d\n", getpid());
	fprintf(filePID, "kill -15 %d", getpid());
	fclose(filePID);

	signal(15, treatsignal);
}