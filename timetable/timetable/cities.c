#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lines.h"
#include <Windows.h>


cities* createStructOfCities(char** argv)
{
    cities* pHeadC = NULL;
    char* text = read(argv);
    const char s[3] = ";-\n";
    char* token;
    token = strtok(text, s);
    while (token != NULL)
    {
        if (token[0] == 42 && token[0] != 13)
        {
            loadCities(&pHeadC, token);
        }
        else if (token[0] != 13 && ((token[0] > 64 && token[0] <= 90) || (token[0] > 96 && token[0] <= 122)))
        {
            loadBustops(&pHeadC, token);
        }
        token = strtok(NULL, s);
    }
    return pHeadC;
}


void addCities(cities** list, cities* newOnes)
{
    newOnes->next = NULL;
    newOnes->bustopsPtr = NULL;
    if ((*list) == NULL)
    {
        *list = newOnes;
    }
    else
    {
        cities* ptr = *list;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newOnes;
    }
}


void loadCities(cities** list, char* name)
{
    cities* newOne = (cities*)malloc(sizeof(cities));
    strcpy(newOne->city, name);
    addCities(list, newOne);
}


void addBustops(bustops** list, bustops* newOnes)
{
    newOnes->next = NULL;
    if ((*list) == NULL)
    {
        *list = newOnes;
    }
    else
    {
        bustops* ptr = *list;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newOnes;
    }
}


void loadBustops(cities** list, char* name)
{
    bustops* newOne = (bustops*)malloc(sizeof(bustops));

    strcpy(newOne->bustop, name);

    cities* ptr = *list;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    addBustops(&ptr->bustopsPtr, newOne);
}


char* read(char** argv)
{
    FILE* read;
    int file;
    read = fopen(/*argv[1]*/"miasta_przystanki.bin", "rb");
    if (!read)
    {
        printf("Can't open the file: \n");
        //exit(-1);
    }
    else
    {
        printf("File opened: \n"/*,argv[1]*/);
    }
    fseek(read, 0, SEEK_END);
    file = ftell(read);
    char* text = malloc(sizeof(char) * (file + 1));
    fseek(read, 0, SEEK_SET);
    fread(text, 1, file + 1, read);
    fclose(read);
    return text;
}


void writeOutCities(cities* list)
{
    cities* ptr = list;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->city);
        writeOutBustops(ptr->bustopsPtr);
        ptr = ptr->next;
    }
}


void writeOutBustops(bustops* list)
{
    bustops* ptr = list;
    while (ptr != NULL)
    {
        printf("\t%s\n", ptr->bustop);
        ptr = ptr->next;
    }
}
