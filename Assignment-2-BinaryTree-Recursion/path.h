typedef struct {
	int *pathArray;
	int size;
	int amountOfEntries;
	} Path;

void PathInit(Path *P, int size);
int PathAddEntry(Path *P, int entry);
int PathRemoveEntry(Path *P);
void PathPrint(Path *P);
