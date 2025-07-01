#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constants.h"

int globalCount = 10;
int score = 0;

char pathMap[] = {"./data/map.txt"};

static int COL = 0;
static int ROW = 0;

static bool isEmpty = true;

int getCOL();
void setCOL(int newCOL);

int getROW();
void setROW(int newROW);

int getUTILC();
int getUTILR();
int getCOLD();
int getROWD();
int getCRD();

bool getIsEmpty();
void setIsEmpty(int newIsEmpty);


int getCOL(){
  return COL;
}
void setCOL(int newCOL){
  COL = newCOL;
}

int getROW(){
  return ROW;
}
void setROW(int newROW){
  ROW = newROW;
}

int getUTILC(){
  return (getCOL() - WALLS);
}
int getUTILR(){
  return (getROW() - WALLS);
}
int getCOLD(){
  return (getCOL() - SPACE);
}
int getROWD(){
  return (getROW() - SPACE);
}
int getCRD(){
  return ((getCOLD() * getROWD()) - 1);
}

bool getIsEmpty(){
  return isEmpty;
}
void setIsEmpty(int newIsEmpty){
  isEmpty = newIsEmpty;
}