#include<iostream>
#include<vector>
#include<random>
#include<chrono>
using namespace std;

namespace Sort{

static inline void mySwap(int &a, int& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

namespace BubbleSort{

class Bubble_Sort{
public:
	void Run(vector<int>& nums){
		int n = nums.size();
		bool exchange = false;
		for(int i=n-1;i>0;i--){
			for(int j=0; j<i; j++){
				if(nums[j]>nums[j+1]){
					mySwap(nums[j], nums[j+1]);
					exchange = true;
				}
			}
			if(!exchange)
				break; // the input array has been completely sorted
		}
	}

};

} // namespace BubbleSort

namespace SeletionSort{

class Seletion_Sort{
public:
	void Run(vector<int>& nums){
		int len = nums.size();
		for(int i=0; i<len-1; i++){
			int min_idx = i;
			for(int j=i+1; j<len; j++){
				if(nums[min_idx]>nums[j])
					min_idx = j;
			}
			// only one exchange for each loop
			mySwap(nums[min_idx], nums[i]);
		}
	}
};

} // namespace SeletionSort

namespace InsertSort{

// stable sort
class Direct_Sort{
public:
	void Run(int arr[], int len){
		for(int i=1; i<len; ++i){
			for(int j=i; j>0; j--){
				if(arr[j] < arr[j-1])
					mySwap(arr[j], arr[j-1]);
			}
		}
	}
};

// stable sort
class Binary_Sort{
public:
	void Run(int arr[], int len){
		int low, high, mid;
		int temp;
		for(int i=1; i<len; i++){
			temp = arr[i];
			low = 0;
			high = i-1;
			// binary search
			while(low<=high){
				mid = (low+high)/2;
				if(arr[mid]>temp)
					high = mid-1;
				else
					low = mid+1;
			}
			// move those behind the inserted element to [high+2:i]
			for(int j=i-1; j>high; j--){
				arr[j+1] = arr[j];
			}
			arr[high+1] = temp;
		}
	}
};

} // namesapace InsertSort


namespace ShellSort{

class shell_sort{
public:
	void Run(vector<int>& nums){
		int n = nums.size();
		int gap = n/2;
		while(gap>0){
			for(int i=0; i<gap; i++)
				gapInsertSort(nums, i, gap);
			gap /= 2;
		}
	}
private:
	void gapInsertSort(vector<int>& nums, int start, int gap){
		int len = nums.size();
		for(int i=start+gap; i<n; i+=gap){
			int position = i;
			int cur =  nums[i];
			// insertion sort
			while(position>start && nums[position-gap]>cur){
				nums[position] = nums[position-gap];
				position = position-gap;
			}
			nums[position] = cur;
		}
	}
};

} // namespace ShellSort

namespace QuickSort{

// !!! Important !!!
// if we choose a value to be pivot randomly,
// first, we should exchange this value with the first or last element in the array
// then the convetional way can be carried out
int PartSort_v1(unsigned int* data, int left, int right){
	unsigned int& pivot = data[left];
	while(left<right){
		// !!!Important!!!
		// thr order of traversal
		while(left<right && data[right]>=pivot)
			right--;

		while(left<right && data[left]<=pivot)
			left++;
		mySwap(data[left], data[right]);
	}
	mySwap(data[left], pivot);
	return left;
}

int PartSort_v2(unsigned int* data, int left, int right){
	unsigned int& pivot = data[left];
	while(left<right){
		while(left<right && data[right]>=pivot)
			right--;
		data[left] = data[right];
		while(left<right && data[left]<=pivot)
			left++;
		data[right] = data[left];
	}
	data[left] = pivot;
	return left;
}

int PartSort_v3_1(unsigned int* data, int left, int right){
	if(left<right){
		unsigned int& pivot = data[right];
		int cur = left;
		int pre = cur-1;
		while(cur<right){
			// from left to right, choose <pivot
			while(data[cur]<pivot && ++pre!=cur)
				mySwap(data[cur], data[pre]);
			++cur;
		}
		mySwap(data[++pre], data[right]);
		return pre;
	}
	return -1;
}

// more important: forward and backward pointer
int PartSort_v3_2(unsigned int* data, int left, int right){
	if (left<right) {
		unsigned int& pivot = data[left];
		int cur = right;
		int pre = right + 1;
		while (cur>left) {
			// !!! Important !!!
			// from right to left, choose >pivot
			while (data[cur]>pivot && --pre != cur)
				mySwap(data[cur], data[pre]);
			--cur;
		}
		mySwap(data[--pre], data[left]);
		return pre;
	}
	return -1;
}

// recursive 
void quickSort_element(unsigned int *data, int left, int right){
	if(left>=right)
		return;
	int index = PartSort_v2(data, left, right);
	quickSort_element(data, left, index-1);
	quickSort_element(data, index+1, right);
}

}// namespace QuickSort


namespace MergeSort{

class merge_sort{
public:
	void Run(vector<int>& nums){
		int n = nums.size();
		__mergeSort(nums, 0, n-1);
	}
private:
	void __mergeSort(vector<int>& nums, int start, int end){
		if(end-start<=15){
			insertionSortHelper(nums, start, end);
			return;
		}

		if(start>=end)
			return;

		int mid = (start+end)/2;
		__mergeSort(nums, start, mid);
		__mergeSort(nums, mid+1, end);

		if(nums[mid] > nums[mid+1])
			merge(nums, start, mid, end);
	}

	// merge two sorted array list
	void merge(vector<int>& nums, int start, int mid, int end){
		vector<int> nums_copy(nums);
		int lstart = start;
		int rstart = mid+1;
		int pos = start;
		while(pos <= end){
			if(lstart > mid){
				nums[pos++] = nums_copy[rstart-start];
				rstart++;
			}else if(rstart>end){
				nums[pos++] = nums_copy[lstart-start];
				lstart++;
			}else if(nums_copy[lstart-start]<nums_copy[rstart-start]){
					nums[pos++] = nums_copy[lstart-start];
					lstart++;
			}else{
				nums[pos++] = nums_copy[rstart-start];
				rstart++;
			}
		}
		return;
	}

	// insert sort
	void insertionSortHelper(vector<int>& nums, int start, int end){
		for(int i=start+1; i<=end; i++){
			int curVal = nums[i];
			int position = i;
			// find the last element whose value is not less than curVal
			while(curVal < nums[position-1] && position>start){
				nums[position] = nums[position-1];
				position--;
			}
			nums[position] = curVal;
		}
	}
};

} // namespace MergeSort

} // namespace Sort


//int main(void){
//	int a[] = {-1,8,6,89,8,22,19,-78,66};
//	InsertSort::Direct_Sort sol1;
//	InsertSort::Binary_Sort sol2;
//	cout<<"Before sorting..."<<endl;
//	for(int i=0;i<9;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//
//	sol1.Run(a, 9);
//	//sol2.Run(a, 9);
//
//	cout<<"After sorting..."<<endl;
//	for(int i=0;i<9;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//
//	return 0;
//}