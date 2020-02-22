#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lines.h"


void deleteLines(lines** pHeadL, int NO)
{
	lines* ptr = searchForLine(*pHeadL, NO);
	lines* ptr1 = *pHeadL;
	lines* ptr2 = NULL;

	while (ptr1 != ptr)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	if (ptr != *pHeadL)
	{
		ptr2->next = ptr->next;
	}
	else
	{
		*pHeadL = (*pHeadL)->next;
	}
	bustopsToL* bustop = ptr->first;
	bustopsToL* var = NULL;
	while (bustop->next != NULL)
	{
		var = bustop;
		bustop = bustop->next;
		free(var);
	}
	free(bustop);
	free(ptr);
}


void deleteBustopFromLines(lines** pHeadL, int NO, char* name)
{
	lines* ptr = searchForLine(*pHeadL, NO);
	bustopsToL* bustop = ptr->first;
	bustopsToL* var = NULL;

	if (strcmp(bustop->toTheName->bustop, name) == 0)
	{
		var = bustop;
		ptr->first = bustop->next;
		free(var);
	}
	else
	{
		while (bustop != NULL && strcmp(bustop->toTheName->bustop, name) != 0)
		{
			var = bustop;
			bustop = bustop->next;
		}
		if (bustop != NULL)
		{
			var->next = bustop->next;
			free(bustop);
		}
	}
}


void deleteBustopFromCity(lines** pHeadL, char* name, cities** pHeadC)
{
	lines* additional = *pHeadL;
	while (additional != NULL)
	{
		deleteBustopFromLines(pHeadL, additional->lineNO, name);
		additional = additional->next;
	}
	cities* var = *pHeadC;
	bustops* bustop = var->bustopsPtr;
	bustops* zzz = NULL;
	while (var != NULL)
	{
		bustop = var->bustopsPtr;
		if (strcmp(bustop->bustop, name) == 0)
		{
			zzz = bustop;
			var->bustopsPtr = bustop->next;
			free(zzz);
		}
		else
		{
			while (bustop != NULL && strcmp(bustop->bustop, name) != 0)
			{
				zzz = bustop;
				bustop = bustop->next;
			}
			if (bustop != NULL)
			{
				zzz->next = bustop->next;
				free(bustop);
			}
		}
		var = var->next;
	}
}


void deleteAll(cities** pHeadC, lines** pHeadL)
{
	lines* var2 = NULL;
	bustopsToL* bustop = NULL;
	bustopsToL* var = NULL;
	while (*pHeadL != NULL)
	{
		var2 = *pHeadL;
		bustop = var2->first;

		while (bustop != NULL)
		{
			var = bustop;
			bustop = bustop->next;
			free(var);
		}
		free(bustop);
		free(var2);
		*pHeadL = (*pHeadL)->next;
	}
	cities* var3 = NULL;
	bustops* bustop1 = NULL;
	bustops* var4 = NULL;
	while (*pHeadC != NULL)
	{
		var3 = *pHeadC;
		bustop1 = var3->bustopsPtr;

		while (bustop1 != NULL)
		{
			var4 = bustop1;
			bustop1 = bustop1->next;
			free(var4);
		}
		free(bustop1);
		free(var3);
		*pHeadC = (*pHeadC)->next;
	}
}