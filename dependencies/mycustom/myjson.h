#ifndef MYJSON_H_
#define MYJSON_H_

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "../pure/cJSON.h"
#include "../../src/constants.h"

extern char *nameFileJson ;
extern char *writeMode; 
extern char *readMode; 
extern FILE *filePointer;
extern char buffer[1024000];
extern cJSON *json;
extern char *jsonString;

typedef enum typeOBjectJson{
    STRING,
    NUMBER,
    ARRAY,
    OBJECT
} typeOBjectJson;

int verifyFile();
int verifyJson();
void getFile(char *nameFile, char *mode);
int setFile(const char *string);
int closeFile();
void convertJSONinString();
int convertBufferToJSON();
void convertStringInJson(char *string);
void writeInFile(const char *string, char *nameFile);
void writeJSONinFile();
void copyFileContentToBuffer(int size, int *length);
void copyFileToBuffer(char *nameFile, int *length);
bool verifyTypeAndLength(cJSON *object, typeOBjectJson type);
void printJSONItem(cJSON *object, typeOBjectJson type, const char *format);
void printJSON();
void modifyJSON();
void inicializeJSONRoot();
void addItemInJSON();
void createJSON();
void readJSON();
void updateJSON();

#endif
