#include <stdio.h> 
#include <stdlib.h>
#include "../pure/cJSON.h"
#include "myjson.h"
#include "../../src/constants.h"

char *nameFileJson = {"tests/data.json"};
char *writeMode = {"w"}; 
char *readMode = {"r"}; 
FILE *filePointer = NULL;
char buffer[1024000];
cJSON *json = NULL;
char *jsonString = NULL;

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
int verifyTypeAndLength(cJSON *object, typeOBjectJson type);
void printJSONItem(cJSON *object, typeOBjectJson type, const char *format);
void printJSON();
void modifyJSON();
void inicializeJSONRoot();
void addItemInJSON();
void createJSON();
void readJSON();
void updateJSON();

int verifyFile(){
    if (filePointer == NULL) { 
        printf("Error: Unable to open the file.\n"); 
        return false; 
    } 
    return true;
}

int verifyJson(){
    if (!(json == NULL)) { 
        return true;
    } 
    const char *errorPointer = cJSON_GetErrorPtr(); 
    if (errorPointer != NULL) { 
        printf("Error: %s\n", errorPointer); 
    } 
    cJSON_Delete(json);
    return false; 
}

void getFile(char *nameFile, char *mode){
    static FILE *temp = NULL;
    temp = fopen(nameFile, mode);
    filePointer = temp;
}

int setFile(const char *string){
    return fputs(string, filePointer);
}

int closeFile(){
    return fclose(filePointer);
}

void convertJSONinString(){
    static char *temp = NULL;
    temp = cJSON_Print(json);
    jsonString = NULL;
    jsonString = temp;
}

int convertBufferToJSON(){
    json = NULL; 
    json = cJSON_Parse(buffer); 
    return (verifyJson() == false) ? false : true;
}

void convertStringInJson(char *string){
    static cJSON *temp = NULL;
    printf("\n%s\n", string);
    temp = cJSON_Parse(string); 
    json = temp;
}

void writeInFile(const char *string, char *nameFile){
    // open json file in write mode 
    getFile(nameFile, writeMode);  
    // verify file is not equals at null
    if(verifyFile() == false) return;
    // write the JSON string to a file  
    setFile(string); 
    // clese the json file
    closeFile(filePointer);
}

void writeJSONinFile(){
    // convert the cJSON object to a JSON string 
    convertJSONinString();
    // print JSON
    // printf("\n%s\n", jsonString);  

    writeInFile(jsonString, nameFileJson);

    cJSON_free(jsonString); 
}

void copyFileContentToBuffer(int size, int *length){
    int len = fread(buffer, size, sizeof(buffer), filePointer);
    if(length != NULL) *length = len;
}

void copyFileToBuffer(char *nameFile, int *length){
    getFile(nameFile, readMode); 
    if(verifyFile() == false) return;
    // int len = 0;
    copyFileContentToBuffer(1, NULL); 
    closeFile(); 
    // if(!length) *length = len;
}

int verifyTypeAndLength(cJSON *object, typeOBjectJson type){
    switch (type){
        case STRING:
            if(!(cJSON_IsString(object))) return false; 
            return true; break;
        case NUMBER:
            if(!(cJSON_IsNumber(object)))return false;
            return true;break;
        case ARRAY:
            if(!(cJSON_IsArray(object)))return false;
            return true;break;
        case OBJECT:
            if(!(cJSON_IsObject(object)))return false;
            return true;break;
    }
}

void printJSONItem(cJSON *object, typeOBjectJson type, const char *format){
    switch (type){
        case STRING:printf(format, object->valuestring);break;
        case NUMBER:printf(format, object->valueint);break;
    }
}

void printJSON(){

    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name");
    if(verifyTypeAndLength(name, STRING) == false) return;
    printJSONItem(name, STRING, "Name: %s\n");

    cJSON *other = cJSON_GetObjectItemCaseSensitive(json, "other"); 
    if(verifyTypeAndLength(other, OBJECT) == false) return;

    cJSON *thing = cJSON_GetObjectItemCaseSensitive(other, "thing"); 
    if(verifyTypeAndLength(thing, STRING) == false) return;
    printJSONItem(thing, STRING, "Thing: %s\n");

    cJSON *anyway = cJSON_GetObjectItemCaseSensitive(other, "anyway"); 
    if(verifyTypeAndLength(anyway, ARRAY) == false) return;

    for (size_t i = 0 ; i < cJSON_GetArraySize(anyway) ; i++){

        cJSON * subitem = cJSON_GetArrayItem(anyway, i);
        if(verifyTypeAndLength(subitem, STRING) == false) return;
        printJSONItem(subitem, STRING, "Anyway: %s\n");

    }

    cJSON *air = cJSON_GetObjectItemCaseSensitive(other, "air");
    if(verifyTypeAndLength(air, ARRAY) == false) return;

    for (size_t i = 0 ; i < cJSON_GetArraySize(air) ; i++){

        cJSON * subitem = cJSON_GetArrayItem(air, i);
        if(verifyTypeAndLength(subitem, OBJECT) == false) return;

        cJSON *a = cJSON_GetObjectItem(subitem, "a");
        if(verifyTypeAndLength(a, NUMBER) == false) return;

        cJSON *b = cJSON_GetObjectItem(subitem, "b");
        if(verifyTypeAndLength(b, NUMBER) == false) return;

        // printf("air: %d - %d\n", a->valueint, b->valueint); 
        printJSONItem(a, NUMBER, "Air: A: %d\n");
        printJSONItem(b, NUMBER, "Air: B: %d\n");

    }
}

void modifyJSON(){
    cJSON_ReplaceItemInObjectCaseSensitive(json, "name", cJSON_CreateString("Jane Doe")); 
    cJSON_AddNumberToObject(json, "age", 32); 
    cJSON_AddStringToObject(json, "phone", "555-555-5555"); 
}

void inicializeJSONRoot(){
    json = cJSON_CreateObject(); 
}

void addItemInJSON(){
    cJSON_AddStringToObject(json, "name", "John Doe"); 
    cJSON_AddNumberToObject(json, "age", 30); 
    cJSON_AddStringToObject(json, "email", "john.doe@example.com"); 
}

void createJSON(){
    // create a cJSON object 
    inicializeJSONRoot();
    // add value in cJSON object
    addItemInJSON();
    // write json in file
    writeJSONinFile();
    // free the JSON string and cJSON object 
    cJSON_Delete(json); 

}

void readJSON(void (*printJSONCustom)(void)){
    // read the file contents into a string 
    copyFileToBuffer(nameFileJson, NULL);
    // parse the JSON data 
    convertBufferToJSON();
    // printf("\nBuffet: %s\n", buffer);
    // access the JSON data 
    printJSONCustom();
    // printJSON();
    // delete the JSON object 
    cJSON_Delete(json); 

}

void updateJSON(){
    // copy content file to buffer
    copyFileToBuffer(nameFileJson, NULL);
    // parse the JSON data 
    if(convertBufferToJSON() == false) return;
    // modify the JSON data 
    modifyJSON();
    // convert the cJSON object to a JSON string 
    convertJSONinString(); 
    // write the JSON string to the file 
    writeInFile(jsonString, nameFileJson);
    // print content json string
    // printf("%s\n", jsonString); 
    // free the JSON string and cJSON object 
    cJSON_free(jsonString); 
    cJSON_Delete(json); 
}
