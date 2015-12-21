#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#define MAXWORDLENGTH 24

//A recursive function that adds each character of the word into the current/child/next node's key depending on if there is already the same key on that level. It also creates the new nodes when necessary. When done adding every character, it creates a leafnode holding the entrie word
void Insert(TrieNode **tNode, char *word, int level)
{
	//checks to make sure we're not traversing past the needed levels of the trie 
	if (level < strlen(word)){
		//if childNode is NULL, means the current node is essentially empty, all nodes in a tri have a childNode unless if it's the leafNode containing the end value
		if((*tNode)->childNode == NULL){
			SetNode(tNode);
			(*tNode)->key = word[level];	//set the current node's key
			(*tNode)->wordPath[level] = word[level];	//add letter into array

			//creating the node's childNode to add the next key (next char in word)
			(*tNode)->childNode = (TrieNode*) malloc(sizeof(TrieNode));
			Insert(&(*tNode)->childNode, word, level+1);
		}
		//else, childNode is NOT NULL
		else
		{ 
			//if node's key is the same as the char being added, move down a level/node
			if((*tNode)->key == word[level]){
				Insert(&(*tNode)->childNode, word, level+1);
			}
			//else, node's key is NOT the same as the char being added
			else
			{
				//if the neighbor/nextNode is NULL, we add a node beside the current one to hold the key
				if ((*tNode)->nextNode == NULL){
					(*tNode)->nextNode = (TrieNode*) malloc(sizeof(TrieNode));
					Insert( &(*tNode)->nextNode, word, level);
				}
				//if the neighbor/nextNode is not NULL, we call the function again to check the nextNode
				else
				{
					Insert( &(*tNode)->nextNode, word, level);
				}	
			}
		}
	}
	//if we added all the characters, we're at the end of the path. The leafnode with the word is added here.
	else if (level == strlen(word))
	{
		(*tNode)->leafNode = (TrieLeafNode*) malloc(sizeof(TrieLeafNode));
		strcpy((*tNode)->leafNode->value, word);
	}
}

//function that sets the Node's values to '0', keeps the nodes clean
void SetNode(TrieNode **tNode)
{
	int i;
	for(i = 0; i < MAXWORDLENGTH; i++)
		(*tNode)->wordPath[i] = '0';
	(*tNode)->key = '0';
}

//A recursive function that traverses through the trie with the given word as the path, then recursively goes through the remaining paths and prints the value of every leafNode encountered (autocompletion)
void TraverseAndPrint(TrieNode **tNode, char *word, int level)
{
	//if level < length of word, continue following the word's path
	if (level < strlen(word)){
		//if childNode is NOT NULL and it's key is the same as the current char we are looking at, continue down the path by going down a level
		if (((*tNode)->childNode != NULL) && ((*tNode)->key == word[level])){
			TraverseAndPrint (&(*tNode)->childNode, word, level+1);
		}
		//if nextNode is NOT NULL, go to the nextNode to check
		if ((*tNode)->nextNode != NULL) {
			TraverseAndPrint (&(*tNode)->nextNode, word, level);
		}
	}

	//if level = length of word, then it has gone through the word's path
	else if (level == strlen(word))
	{
		//if the current node has a leafNode, print it, it is an autocompleted word
		if ((*tNode)->leafNode != NULL)
			printf ("%s\n", (*tNode)->leafNode->value);
		//if childNode is not NULL, traverse to that path
		if ((*tNode)->childNode != NULL){
			TraverseAndPrint (&(*tNode)->childNode, word, level);
		}
		//if nextNode is not NULL, traverse to that path
		if ((*tNode)->nextNode != NULL) {
			TraverseAndPrint (&(*tNode)->nextNode, word, level);;
		}

	}
}
