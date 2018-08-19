#include<iostream>
#include<string>
#include "Trie_Tree.h"

using namespace std;

// Trie的核心思想是空间换时间。
//利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的

// construction function
Trie_Tree::TrieNode::TrieNode(){
	data = nullptr;
	for(int i=0;i<num_chars;i++){
		branch[i] = nullptr;
	}
}
// construction function
Trie_Tree::Trie_Tree():root(nullptr){
}

// deconstruction function
Trie_Tree::~Trie_Tree(){}

// search 
int Trie_Tree::trie_search(const char* word, const char* entry) const{
	int position = 0;
	char char_code;
	TrieNode* location = root;
	while(location != nullptr && *word != 0){
		if(*word>='A' && *word<='Z')
			char_code = *word-'A';
		else if(*word>='a' && *word<='z')
			char_code = *word-'a';
		else 
			return ERROR;
		location = location->branch[char_code];
		position++;
		word++;
	}
	// find result
	if(location != nullptr && location->data!=nullptr){
		strcpy(entry, location->data);
		return OK;
	}
	else
		return ERROR;
}

// insert node
int Trie_Tree::insert(const char* word, const char* entry) {   
	int result = 1, position = 0;   
	if ( root == nullptr ) 
		root = new TrieNode;   //初始插入，根结点为空 
	char char_code;   
	TrieNode *location = root;   //从根结点开始 
	while( location!=nullptr && *word!=0 ) {       
		if (*word>='A' && *word<='Z') 
			char_code = *word-'A';       
		else if (*word>='a' && *word<='z') 
			char_code = *word-'a';       
		else 
			return 0;// 不合法的单词    
 
		//不存在此分支 
		if( location->branch[char_code] == nullptr )            
			location->branch[char_code] = new TrieNode;    //创建空分支   
 
		//转入分支 
		location = location->branch[char_code];       
		position++;
		word++;   
	}   
	if (location->data != nullptr) 
		result = 0;//欲插入的单词已经存在    
	else {    //插入数据     
		location->data = new char[strlen(entry)+1];     //分配内存    
		strcpy(location->data, entry);    //给data赋值表明单词存在 
	}   
	return result;	
}

