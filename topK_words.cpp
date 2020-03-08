#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<queue>
#include<functional>
#include<unordered_map>
using namespace std;
using pp = pair<string, int>;

class Solution{
public:
	Solution(int k): k_(k){}
	~Solution() {} 

	static inline void mySwap(pp& a, pp& b){
		pp tmp = a;
		a = b;
		b = tmp;
	}

	// 
	static inline void minHeap(vector<pp>& array, int start, int end){
		int lchild;
		while(1){
			lchild = 2*start+1;
			if(lchild>end)
				break;
			// compare left and right child
			if(lchild+1<=end && array[lchild].second>array[lchild+1].second)
				lchild+=1;
			// compare the root with 
			if(array[lchild].second > array[start].second){
				mySwap(array[start], array[lchild]);
				start = lchild;
			}
			else
				break;
		}
	}

	static inline void initHeap(vector<pp>& array){
		// starting with the first non-leaf node
		int start = array.size()/2-1;
		for(int i=start; i>=0; i--){
			minHeap(array, i, array.size()-1);
		}
	}

	// use new element to update heap
	static inline void updateHeap(vector<pp>& array, const pp& new_ele){
		array[0] = new_ele;
		// from top to bottom
		minHeap(array, 0, array.size()-1);
	}

	// step0: read words from txt file
	void readDataFromFile(const char *fileName){
		ifstream strFile(fileName);
		string tmp;
		while(getline(strFile, tmp)){
			wordList.push_back(tmp);
			tmp.clear();
		}
		return;
	}
	
	//step1: use hash to divide all words into different parts

	//step2: use hash table to count all words
	void countWordsFrequency(void){
		for(auto item : wordListPart){
			if(wordsCount.find(item) != wordsCount.end())
				wordsCount[item]++;
			else
				wordsCount[item] = 1;
		}
	}

	//step3: create min heap to find the top K words
	void findTopK_bySTL(void){
		int t=0;
		for(auto item : wordsCount){
			if(t<k_){
				topK_list.push(item);
			}else{
				if(item.second > topK_list.top().second){
					topK_list.pop();
					topK_list.push(item);
				}
			}
			t++;
		}
	}

	// 
	void findTopK_byNaive(void){
		int t=0;
		vector<pp> topK_heap;
		for(auto item : wordsCount){
			if(t<k_){
				topK_heap.push_back(item);
			}else{
				if(t == k_)
					initHeap(topK_heap);
				else{
					// insert the new element and delete the smallest element
					if(item.second>topK_heap[0].second){
						updateHeap(topK_heap, item);
					}
				}
			}
		}
	}
private:
	vector<string> wordList;
	vector<string> wordListPart;
	struct cmp {
		bool operator ()(pp a, pp b) {
			return a.second>b.second;
		}
	};
	priority_queue<pp, vector<pp>, cmp> topK_list;
	unordered_map<string, int> wordsCount;
	int k_;
	
};