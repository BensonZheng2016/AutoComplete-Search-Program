/**
 * CPS305 Assignment 2 - PathFinder (recursively finds all paths of array)
 * Due October 20 2015
 * @author Alvin Ho
 */
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "path.h"
int numberOfPaths;

int main ()
{
	Vector *V = (Vector *)malloc(sizeof(Vector));
	VectorRead(V);

	numberOfPaths = 0;
	printf ("Solutions:\n");
	findPaths(V, V->size);

	//checking how many solutions
	if (numberOfPaths == 0) printf ("There were no solutions.\n");
	else printf ("\nThere were %d solutions.\n", numberOfPaths);
}

//initializes an empty path P and call the recursive function AllPathsRec() to find the paths
int findPaths(Vector *V, int size)
{
	Path *P = (Path *)malloc(sizeof(Path)); //DMA of Path P
	PathInit(P, size);
	AllPathsRec(0, V, P, 0);
}


//A recursive function that finds all the paths of the array... uses Binary-Tree as a model
int AllPathsRec(int pos, Vector *V, Path *Solution, int children)
{
	PathAddEntry(Solution, pos); //adds current position/index to the path

	//if the last entry of the path is at the end of the array, print the solution.
	if (Solution->pathArray[Solution->amountOfEntries-1] == V->size-1){
		PathPrint(Solution);
		numberOfPaths++;
	}

	//if going back on same path, cancel this pathway by putting children=2
	if (repeatingSamePath(Solution) == 1) children = 2;

	//if no children, makes the pathway go to the right of the array
	if (children == 0)
	{
		children++;
		//checks if we make the path go right, will it pass the boundry and if it already reached the end of array
		if ((pos + V->item[pos] < V->size) && (Solution->pathArray[Solution->amountOfEntries-1] != V->size-1)){
			AllPathsRec(pos + V->item[pos], V, Solution, 0);
		}
	}

	//if 1 child, makes the pathway go to the left of the array
	if (children == 1)
	{
		children++;
		//checks if we make the path go right, will it pass the boundry and if it already reached the end of array
		if ((pos - V->item[pos] > 0) && (Solution->pathArray[Solution->amountOfEntries-1] != V->size-1)){
			AllPathsRec(pos - V->item[pos], V, Solution, 0);
		}
	}

	//if there are two children already at this position, go back (remove last entry since dead end).
	if (children == 2) PathRemoveEntry(Solution);
}

//A function that checks if the path is starting to repeat itself
int repeatingSamePath(Path *P)
{
	int i;
	for (i = 0; i < P->amountOfEntries-1; i++){
		if (P->pathArray[P->amountOfEntries-1] == P->pathArray[i]) return 1;
	}
	return 0;
}
