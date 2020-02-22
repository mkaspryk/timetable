#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lines.h"


void changeNameOfBustop(cities** city)
{
    char oldName[100];
    char newName[100];
    printf("Please enter the name of the bus stop do you want to change ?\n");
    scanf("%s", oldName);
    bustops* searched = searchForBustop(oldName, city);
    while (searched == NULL)
    {
        printf("No bus stop found in the cities.\n");
        printf("Please enter the name of the bus stop do you want to change ?\n");
        scanf("%s", oldName);
        bustops* searched = searchForBustop(oldName, city);
    }
    printf("Enter the name you want to change to the name %s \n", searched->bustop);
    scanf("%s", newName);
    strcpy(searched->bustop, newName);
}


void saveToFileStructOfCities(cities* list, char** argv)
{
    FILE* strC;
    strC = fopen(/*argv[3]*/"zapis_miasta.bin", "wb");
    if (strC == NULL) {
        printf("Can't open the file zapis_miasta.bin to save!\n");
    }
    saveToFileCities(list, &strC);
    fclose(strC);
}


void saveToFileCities(cities* list, FILE** str)
{
    cities* ptr = list;
    while (ptr != NULL)
    {
        fprintf(*str, "%s;", ptr->city);
        saveToFileBustops(ptr->bustopsPtr, str);
        ptr = ptr->next;
    }
}


void saveToFileBustops(bustops* list, FILE** str)
{
    bustops* ptr = list;
    while (ptr != NULL)
    {
        fprintf(*str, "%s-", ptr->bustop);
        ptr = ptr->next;
    }
}


void saveToFileStructOfLines(lines* list, char** argv)
{
    FILE* strL;
    strL = fopen(/*argv[4]*/"zapis_linie.bin", "wb");
    if (strL == NULL) {
        printf("Can't open the file zapis_linie.bin to save!\n");
    }
    saveToFileLines(list, &strL);
    fclose(strL);
}


void saveToFileLines(lines* list, FILE** str)
{
    lines* ptr = list;
    while (ptr != NULL)
    {
        fprintf(*str, "%d;", ptr->lineNO);
        saveToFileBustopsToLine(ptr->first, str);
        ptr = ptr->next;
    }
}


void saveToFileBustopsToLine(bustopsToL* list, FILE** str)
{
    bustopsToL* ptr = list;
    while (ptr != NULL)
    {
        fprintf(*str, "%s-", ptr->toTheName->bustop);
        ptr = ptr->next;
    }
}