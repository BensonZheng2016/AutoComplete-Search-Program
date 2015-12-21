typedef struct trienode {
	char data[24];			//holds the word (if there is one in the node)
	char key;			//holds the character
	struct trienode *Children[127]; //127 basic ascii codes 
}trienode;

void printWords(trienode **current);
void Insert(char word[], trienode **Root);
void Search(char *word, trienode *Root);
trienode* getTrieNode();
