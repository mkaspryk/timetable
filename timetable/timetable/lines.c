#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lines.h"


void addLines(lines** list, lines* newOne)
{
    newOne->next = NULL;
    newOne->first = NULL;
    if ((*list) == NULL)
    {
        *list = newOne;
    }
    else
    {
        lines* ptr = *list;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newOne;
    }
}


void loadLines(lines** list, int NO)
{
    lines* newOne = (lines*)malloc(sizeof(lines));
    newOne->lineNO = NO;
    addLines(list, newOne);
}


void addBustopToL(bustopsToL** list, bustopsToL* newOne)
{
    newOne->next = NULL;
    if ((*list) == NULL)
    {
        *list = newOne;
    }
    else
    {
        bustopsToL* ptr = *list;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;

        }
        ptr->next = newOne;
    }
}


void loadBustopsToLine(lines** list, char* name, cities** city)
{
    bustopsToL* newOne = (bustopsToL*)malloc(sizeof(bustopsToL));
    newOne->toTheName = searchForBustop(name, city);
    lines* ptr = *list;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    addBustopToL(&ptr->first, newOne);
}


char* readLines(char** argv)
{
    FILE* read;
    int file;
    read = fopen("linie.bin", "rb");
    if (!read)
    {
        fprintf(stderr, "Can't open the file: \n");
        //exit(-1);
    }
    else
    {
        printf("File opened: \n");
    }
    fseek(read, 0, SEEK_END);
    file = ftell(read);
    char* text = malloc(sizeof(char) * (file + 1));
    fseek(read, 0, SEEK_SET);
    fread(text, 1, file + 1, read);
    fclose(read);
    return text;
}


bustops* searchForBustop(char* name, cities** list)
{
    cities* ptr = *list;
    while (ptr != NULL)
    {
        bustops* ptr2 = ptr->bustopsPtr;
        while (ptr2 != NULL)
        {
            if (strcmp(ptr2->bustop, name) == 0)
            {
                return ptr2;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr = ptr->next;
    }
    return NULL;
}


cities* searchForCity(char* name, cities** list)
{
    cities* ptr = *list;
    while (ptr != NULL)
    {
        if (strcmp(ptr->city, name) == 0)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}


void writeOutLines(lines* list)
{
    lines* ptr = list;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->lineNO);
        writeOutBustopsToLine(ptr->first);
        ptr = ptr->next;
    }
}

void writeOutBustopsToLine(bustopsToL* list)
{
    bustopsToL* ptr = list;
    while (ptr != NULL)
    {
        printf("\t%s\n", ptr->toTheName->bustop);
        ptr = ptr->next;
    }
}


lines* createStructOfLines(cities** city, char** argv)
{
    lines* pHeadL = NULL;
    char* text = readLines(argv);
    const char s[3] = ";-\n";
    char* token;
    token = strtok(text, s);
    while (token != NULL)
    {
        if (token[0] > 48 && token[0] <= 57)
        {
            int number = atoi(token);
            loadLines(&pHeadL, number);
        }
        else if (token[0] != 13 && ((token[0] > 64 && token[0] <= 90) || (token[0] > 96 && token[0] <= 122)))
        {
            loadBustopsToLine(&pHeadL, token, city);
        }
        token = strtok(NULL, s);
    }
    return pHeadL;
}