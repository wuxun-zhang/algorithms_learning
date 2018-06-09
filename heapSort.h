#pragma once

// 元素交换
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 建立大顶堆
void maxHeap(int array[], int start, int end)
{
	int lchild;
	while (1)
	{
		// 从当前父节点的左孩子开始比较
		lchild = 2 * start + 1;

		if (lchild > end)
			break;
		// 取左右孩子中的最大值
		if (lchild + 1 <= end && array[lchild] < array[lchild + 1])
			lchild += 1;
		// 当左右孩子的最大值大于父节点值时，将这两个元素交换
		if (array[lchild] > array[start])
		{
			swap(&array[lchild], &array[start]);
			start = lchild;
		}
		else
			break;
	}
}

// 建立小顶堆
void minHeap(int array[], int start, int end)
{
	int lchild;
	while (1)
	{
		// 从当前父节点的左孩子开始比较
		lchild = 2 * start + 1;

		if (lchild > end)
			break;
		// 取左右孩子中的最大值
		if (lchild + 1 <= end && array[lchild] > array[lchild + 1])
			lchild += 1;
		// 当左右孩子的最大值大于父节点值时，将这两个元素交换
		if (array[lchild] < array[start])
		{
			swap(&array[lchild], &array[start]);
			start = lchild;
		}
		else
			break;
	}
}

void heapSort(int array[], int length, bool isAscending)
{
	//	从第一个非叶节点开始
	int start = length / 2 - 1;	
	// 初始化大顶堆
	for (int i = start; i >= 0; i--)
	{
		if (isAscending)
			maxHeap(array, i, length - 1);
		else
			minHeap(array, i, length - 1);
	}

	// 开始堆排序
	for (int i = length-1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		// 重新调整堆结构
		if (isAscending)
			maxHeap(array, 0, i - 1);
		else
			minHeap(array, 0, i - 1);
	}
}

// 返回一组二元组序列的最小差对数、最大差对数
vector<int> interestNumbers(int N, int nums[])
{
	map<int, int> myMap;
	int min_Dvalue = 0, tmp_Dvalue = 0;
	// step0：对输入数组采用堆排序算法进行升序排列，时间复杂度为O(nlogn)
	heapSort(nums, N, true);
	// step1：数组中的值全部相等
	if (nums[0] == nums[N - 1])
		return vector<int>((N - 1)*N / 2, (N - 1)*N / 2);

	//step2：统计每个数字出现的次数
	for (int i = 0; i < N; i++)
	{
		if (myMap.find(nums[i]) == myMap.end())
			myMap.insert(make_pair(nums[i], 1));	// 初始化阶段
		else
			myMap.find(nums[i])->second++;
	}
	// step3：计算最小差值的个数,要分有重复值和没有重复值两种情况
	// 第一种：数组中不存在重复值
	int first_count, end_count;	// 统计最小值、最大值出现次数
	int minDvalue_count = 0, maxDvalue_count = 0;
	if (myMap.size() == N)
	{
		min_Dvalue = nums[1] - nums[0];
		for (int i = 2; i < N; i++)
		{
			tmp_Dvalue = nums[i] - nums[i - 1];
			if (tmp_Dvalue == min_Dvalue)
			{
				minDvalue_count++;
			}
			else if (tmp_Dvalue < min_Dvalue)
			{
				minDvalue_count = 1;	// 当出现更小的差值对时，计数器置1，重新开始
				min_Dvalue = tmp_Dvalue;
			}
		}
	}
	else
	{
		map<int, int>::iterator map_it;
		for (map_it = myMap.begin(); map_it != myMap.end(); map_it++)
		{
			int k;
			if ((k = map_it->second) > 1)
			{
				minDvalue_count += k*(k - 1) / 2;
			}
		}
	}
	first_count = myMap.find(nums[0])->second;
	end_count = myMap.find(nums[N - 1])->second;
	maxDvalue_count = first_count*end_count;

	vector<int> results;
	results.push_back(minDvalue_count);
	results.push_back(maxDvalue_count);
	return results;
}
