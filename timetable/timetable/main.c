#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lines.h"


void Menu(lines** pHeadL, cities** pheadC, char** argv);


int main(int argc, char** argv)
{
	cities* pHeadC = createStructOfCities(argv);
	lines* pHeadL = createStructOfLines(&pHeadC, argv);
	Menu(&pHeadL, &pHeadC, argv);
	system("pause");
	return 0;
}


void Menu(lines** pHeadL, cities** pHeadC, char** argv)
{
	int var;
	char bustop[100];
	int d;
	printf("Welcome in timetable!\n");
	printf("Select one of the functions given.\n If you want to end program select 'k'\n");
	printf("1 - Change the name of bus stop.\n");              // modifying.c
	printf("2 - Add new line.\n");                             // add.c
	printf("3 - Add bus stop to line.\n");                     // add.c
	printf("4 - Add bus stop to city.\n");                     // add.c
	printf("5 - Delete line.\n");                              // deleting.c
	printf("6 - Delete bus stop from line.\n");                // deleting.c
	printf("7 - Delete bus stop from city and from line.\n");  // deleting.c
	printf("8 - Print out timetable.\n");                      // line.c and cities.c

	while (var = getchar())
	{
		switch (var)
		{
		case 49:                                                   // ASCII numer 1
			changeNameOfBustop(pHeadC);
			saveToFileStructOfCities(*pHeadC, argv);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 50:                                                   // ASCII numer 2
			addLineFromTerminal(pHeadL);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 51:                                                   // ASCII numer 3
			addBustopToLine(pHeadL, *pHeadC);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 52:                                                   // ASCII numer 4
			addBustopToCity(pHeadC);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 53:                                                   // ASCII numer 5
			printf("Which line do you want to delete from the timetable?\n");
			scanf("%d", &d);
			deleteLines(pHeadL, d);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 54:                                                   // ASCII numer 6
			printf("From which line do you want to delete bus stop?\n");
			scanf("%d", &d);
			printf("Which bus stop do you want to delete from the line?\n");
			scanf("%s", bustop);
			deleteBustopFromLines(pHeadL, d, bustop);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 55:                                                   // ASCII numer 7
			printf("Which bus stop do you want to delete from the city and the line?\n");
			scanf("%s", bustop);
			deleteBustopFromCity(pHeadL, bustop, pHeadC);
			saveToFileStructOfCities(*pHeadC, argv);
			saveToFileStructOfLines(*pHeadL, argv);
			break;
		case 56:                                                  // ASCII numer 8
			writeOutLines(*pHeadL);
			writeOutCities(*pHeadC);
			break;
		case 75:                                                  // ASCII k
			exit(0);
			break;
		case 107:                                                 // ASCII K
			exit(0);
			break;
		default:
			printf("You have chosen the wrong key. Please try again.\n");
			break;
		}
	}
}
