#include<stdio.h>
#include<stdlib.h>
#include"trie.h"

int main()
{
	trienode *trie = getTrieNode();

	FILE *f = fopen("american-english-no-accents", "r");

	char word[24];
	while (feof(f) == 0){
		fscanf(f, "%s", word);
		Insert(word, &trie);
	}

	char input[255];
	while(!feof(stdin)){
		printf ("Search: ");
		scanf("%s", input);
		Search(input, trie);
	}
}
