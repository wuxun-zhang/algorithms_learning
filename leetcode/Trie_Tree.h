#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_

#define TRUE  	1
#define FALSE 	0
#define OK		1
#define NULL	0
#define ERROR	0


static const int num_chars = 26;
class TrieTree{
public:
	TrieTree();
	TrieTree(TrieTree& tr);
	virtual ~TrieTree();
	int trie_search(const char * word, const char* entry) const;
	int insert(const char *word, const char *entry);
	int remove(const char *word, char *entry);
protected:
	struct TrieNode{
		char *data;
		TrieNode* branch[num_chars];
		TrieNode();
	};
	TrieNode* root;
};

#endif