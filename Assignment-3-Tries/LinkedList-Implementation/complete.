#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#define MAXWORDLENGTH 24  //max word length in the dictionary

void InsertWordsFromFile(TrieNode **tNode, char *fileName);
void AutoComplete(TrieNode **tNode);

//Main function that creates the trie "t", calls the function to read the wordlist file, and runs the autocomplete function
int main()
{
	TrieNode *t;
	t = (TrieNode*) malloc(sizeof(TrieNode));
	InsertWordsFromFile(&t, "american-english-no-accents"); //wordlist path
	AutoComplete(&t);
}

//function reads each word from the file, calls the Insert function from the trie ADT to insert the word into the trie
void InsertWordsFromFile(TrieNode **tNode, char *fileName)
{
	FILE *f = fopen(fileName, "r");
	char word[MAXWORDLENGTH];

	while (feof(f) == 0){
		fscanf(f, "%s", word);
		Insert(tNode, word, 0);
	}

	printf("Inserted list of words from '%s' into trie.\n(crtl+D to end program)\n", fileName); 
}

//function asks for user input, scans the input, and calls TraverseAndPrint from the trie ADT (searches and prints all words with matching prefix)
void AutoComplete(TrieNode **tNode)
{
	char userSearch[100];
	while(!feof(stdin)){	//while loop until user enters crtl-D to indicated EOF
		printf ("\nSearch: ");
		scanf("%s", userSearch);
		printf ("Results:\n");
		TraverseAndPrint(tNode, userSearch, 0);
		userSearch[0] = '0';
	}
}
