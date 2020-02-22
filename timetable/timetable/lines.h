#ifndef LINES_H_
#define LINES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cities cities;
/**
* Structure of cities
*/
struct cities
{
    char city[200];
    struct cities* next;
    struct bustops* bustopsPtr;
};

typedef struct bustops bustops;
/**
* Structure of bus stops
*/
struct bustops
{
    char bustop[200];
    bustops* next;
};

typedef struct bustopsToL bustopsToL;
/**
* Structure of bus stops to line
*/
struct bustopsToL
{
    int bustopNO;
    bustops* toTheName;
    bustopsToL* next;
};

typedef struct lines lines;
/**
*  Structure of lines
*/
struct lines
{
    int lineNO;
    bustopsToL* first;
    lines* next;
};

//---deleting.c--//
/**
* Function deletes all lines from memory (structure)
*/
void deleteLines(lines** pHeadL, int NO);
/**
* Function deletes all bus stops from lines
*/
void deleteBustopFromLines(lines** pHeadL, int NO, char* name);
/**
* Function deletes all bus stops from cities
*/
void deleteBustopFromCity(lines** pHeadL, char* name, cities** pHeadC);
/**
* Function clears all memory
*/
void deleteAll(cities** pHeadC, lines** pHeadL);

//---modifying.c--//
/**
* Function changes name of bus stop
*/
void changeNameOfBustop(cities** city);
/**
* Function saves to file structure of cities
*/
void saveToFileStructOfCities(cities* list, char** argv);
/**
* Function saves to file cities
*/
void saveToFileCities(cities* list, FILE** str);
/**
* Function saves to file bus stops
*/
void saveToFileBustops(bustops* list, FILE** str);
/**
* Function saves to file structure of lines
*/
void saveToFileStructOfLines(lines* list, char** argv);
/**
* Function saves to file lines
*/
void saveToFileLines(lines* list, FILE** str);
/**
* Function saves to file bus stops to line
*/
void saveToFileBustopsToLine(bustopsToL* list, FILE** str);

//--add.c--//
/**
* Function adds new line from terminal
*/
void addLineFromTerminal(lines** pHeadL);
/**
* Function adds bus stop to the line
*/
void addBustopToLine(lines** pHeadL, cities* city);
/**
* Function adds bus stop to city
*/
void addBustopToCity(cities** cityPtr);
/**
* Function checks the line exist
*/
bool checkLine(lines* pHeadL, int NO); 
/**
* Function searches for the line
*/
lines* searchForLine(lines* pHeadL, int NO);

//---cities.c--//
/**
* Function creates structure of cities
*/
cities* createStructOfCities(char** argv);
/**
* Function adds the cities
*/
void addCities(cities** list, cities* newOnes);
/**
* Function loads the cities
*/
void loadCities(cities** list, char* name);
/**
* Function adds bus stops
*/
void addBustops(bustops** list, bustops* newOnes);
/**
* Function loads the bus stops
*/
void loadBustops(cities** list, char* newOnes);
/**
* Function reads argv
*/
char* read(char** argv);
/**
* Function prints out the cities
*/
void writeOutCities(cities* list);
/**
* Function prints out the bus stops
*/
void writeOutBustops(bustops* list);

//--lines.c--//
/**
* Function adds the lines
*/
void addLines(lines** list, lines* newOne);
/**
* Function loads the lines
*/
void loadLines(lines** list, int NO); 
/**
* Function adds bus stop to the line
*/
void addBustopToL(bustopsToL** list, bustopsToL* newOne);
/**
* Function loads bus stop to the line
*/
void loadBustopsToLine(lines** list, char* name, cities** city);
/**
* Function reads the lines
*/
char* readLines(char** argv);
/**
* Function searches for bus stop
*/
bustops* searchForBustop(char* name, cities** list);
/**
* Functiom searches for the city
*/
cities* searchForCity(char* name, cities** list);
/**
* Function print out the lines 
*/
void writeOutLines(lines* list);
/**
* Function print out bus stops to line
*/
void writeOutBustopsToLine(bustopsToL* list);
/**
* Function creates structure of lines
*/
lines* createStructOfLines(cities** city, char** argv);

#endif// LINIE_H_INCLUDED
