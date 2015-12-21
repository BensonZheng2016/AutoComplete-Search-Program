#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

/**
* reads two lines from stdin. The first line is read to obtain the the
size of the array for V->item for DMA. The second line is then read
to obtain the array values to be inserted into V->item.
*/
void VectorRead(Vector *V)
{
	int N, i, value;
	char buffer[256];

	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &N);
	V->size = N;

	V->item = (int *)malloc(sizeof(int)*N); //DMA for V->item array based on size N
	
	//gets second line, reads through the values of base 10, inserts each into array
	fgets(buffer, sizeof(buffer), stdin);
	char *num = buffer;
	for (i = 0 ; i != N ; i++) {
		value = strtol(num, &num, 10);
		V->item[i] = value;
	}

	printf ("Size:\t%d\n", V->size); 
	printf("Array:\t");
	//loops through and prints each value in array
	for (i = 0 ; i != N ; i++) {
		printf("[%d]", V->item[i]);
	}
	printf("\n\n");
}
