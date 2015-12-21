typedef struct TrieLeafNode{
	char value[24];
}TrieLeafNode;

typedef struct TrieNode{
	char key;			//the current node's letter
	char wordPath[24];		//indexes the characters
	struct TrieNode *childNode;	//child node that branches from current node
	struct TrieNode *nextNode;	//node beside the current node, "neighbor"
	struct TrieLeafNode *leafNode;	//leaf node that holds the word
	}TrieNode;

void Insert(TrieNode **tNode, char *word, int level);
void SetNode(TrieNode **tNode);
void TraverseAndPrint(TrieNode **tNode, char *userSearch, int level);
