#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lines.h"


void addLineFromTerminal(lines** pHeadL)
{
    int num;
    char nums[20];
    printf("You can now add your own line.\n");
    printf("Which line number do you want to add?\n");
    scanf("%s", nums);
    num = atoi(nums);
    lines* ptr = *pHeadL;
    while (checkLine(ptr, num))
    {
        printf("Selected line number is already exist.\n");
        printf("Please try again.\n");
        scanf("%d", &num);
    }
    loadLines(pHeadL, num);
}


void addBustopToLine(lines** pHeadL, cities* city)
{
    char name[100];
    int num;
    printf("To which line do you want to add bus stop?\n");
    scanf("%d", &num);
    lines* lineS = searchForLine(*pHeadL, num);
    while (lineS == NULL)
    {
        printf("No line found to which you want to add a bus stop.\n");
        printf("To which line do you want to add a bus stop?\n");
        scanf("%d", &num);
        lineS = searchForLine(*pHeadL, num);;
    }
    bustopsToL* newOne = (bustopsToL*)malloc(sizeof(bustopsToL));
    printf("Select the name of the bus stop you want to add to the line ?\n");
    scanf("%s", name);
    bustops* searched = searchForBustop(name, &city);
    while (searched == NULL)
    {
        printf("No bus stop found in the cities.\n");
        printf("Select the name of the bus stop you want to add to the line ?\n");
        scanf("%s", name);
        searched = searchForBustop(name, &city);
    }
    newOne->toTheName = searched;
    addBustopToL(&lineS->first, newOne);
    printf("Bus stop was added.\n");
}


void addBustopToCity(cities** cityPtr)
{
    char city[100];
    char bustop[100];
    printf("To which city do you want add bus stop?\n");
    scanf("%s", city);
    cities* searchedC = searchForCity(city, cityPtr);
    while (searchedC == NULL)
    {
        printf("No city found to which you want to add a bus stop.\n");
        printf("To which city do you want add bus stop?\n");
        scanf("%s", city);
        searchedC = searchForCity(city, cityPtr);
    }
    bustops* newOne = (bustops*)malloc(sizeof(bustops));
    printf("Select the name of the bus stop you want to add to the city ?\n");
    scanf("%s", bustop);
    strcpy(newOne->bustop, bustop);
    addBustops(&searchedC->bustopsPtr, newOne);

}


bool checkLine(lines* pHeadL, int NO)
{
    lines* ptr = pHeadL;
    while (ptr != NULL)
    {
        if (ptr->lineNO == NO)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}


lines* searchForLine(lines* pHeadL, int NO)
{
    lines* ptr = pHeadL;
    while (ptr != NULL)
    {
        if (ptr->lineNO == NO)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}