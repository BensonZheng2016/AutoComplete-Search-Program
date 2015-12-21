#include "path.h"
#include <stdio.h>
#include <stdlib.h>

void PathInit(Path *P, int size)
{
	P->pathArray = (int *)malloc(sizeof(int)*size);
	P->size = size;
	P->amountOfEntries = 0;
}

//adds entry to the last empty slot of the array
int PathAddEntry(Path *P, int entry)
{
	P->pathArray[P->amountOfEntries] = entry;
	P->amountOfEntries++;
}

//changes the very last entry of the array to -1 (removing that entry)
int PathRemoveEntry(Path *P)
{
	P->pathArray[P->amountOfEntries] = -1;
	P->amountOfEntries--;
}

void PathPrint(Path *P)
{
	int i;
	for (i = 0 ; i != P->amountOfEntries ; i++) {
		printf("%d ", P->pathArray[i]);
	}
	printf ("\n");
}
