#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"trie.h"

//creating and setting default values for node
trienode* getTrieNode()
{
	int count;
	trienode *tempNode = (trienode*)malloc(sizeof(trienode));
	for(count=0; count<123; count++)
	{
		tempNode->Children[count] = NULL;
	}
	tempNode->key = '0';
	tempNode->data[0] = '0';
	return tempNode;
}

//inserts word into node
void Insert(char word[], trienode **firstNode)
{
	trienode *Trie = (*firstNode);
	int level, Index;

	//for loop creates goes through word path and creates a new node in child array when necessary
	for(level=0; level < strlen(word); level++)
	{
		Index = word[level];
		if((Trie->Children[Index])==NULL)
		{
			Trie->Children[Index] = getTrieNode();
		}
		Trie = Trie->Children[Index];
		Trie->key = word[level];
	}
	strcpy(Trie->data, word);
}

//recursively finds the rest of the words and prints remaining words
void printWords(trienode **current)
{
	int count2;
	if ((*current)->data[0] != '0')
		printf ("%s\n", (*current)->data);
	for (count2 = 0; count2 < 127; count2++){
		if ((*current)->Children[count2] != NULL){
			printWords(&(*current)->Children[count2]);
		}
	}
}

//goes through the search word's path in the trie
void Search(char *word, trienode *Root)
{
	int count, thereAreWords=1;
	trienode* current=Root;
	for(count=0; count<strlen(word); count++)
	{
		int Index = word[count];
		if (current->Children[Index]!=NULL)
		{
			current=current->Children[Index];
		}
		else
		{
			thereAreWords = 0;
			break;
		}
	}
	if (thereAreWords == 1) printWords(&current);
	if (thereAreWords == 0) printf("No words start with %s\n",word);
}
