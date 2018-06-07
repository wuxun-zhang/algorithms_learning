#pragma once

// Ԫ�ؽ���
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// �����󶥶�
void maxHeap(int array[], int start, int end)
{
	int lchild;
	while (1)
	{
		// �ӵ�ǰ���ڵ�����ӿ�ʼ�Ƚ�
		lchild = 2 * start + 1;

		if (lchild > end)
			break;
		// ȡ���Һ����е����ֵ
		if (lchild + 1 <= end && array[lchild] < array[lchild + 1])
			lchild += 1;
		// �����Һ��ӵ����ֵ���ڸ��ڵ�ֵʱ����������Ԫ�ؽ���
		if (array[lchild] > array[start])
		{
			swap(&array[lchild], &array[start]);
			start = lchild;
		}
		else
			break;
	}
}

// ����С����
void minHeap(int array[], int start, int end)
{
	int lchild;
	while (1)
	{
		// �ӵ�ǰ���ڵ�����ӿ�ʼ�Ƚ�
		lchild = 2 * start + 1;

		if (lchild > end)
			break;
		// ȡ���Һ����е����ֵ
		if (lchild + 1 <= end && array[lchild] > array[lchild + 1])
			lchild += 1;
		// �����Һ��ӵ����ֵ���ڸ��ڵ�ֵʱ����������Ԫ�ؽ���
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
	//	�ӵ�һ����Ҷ�ڵ㿪ʼ
	int start = length / 2 - 1;	
	// ��ʼ���󶥶�
	for (int i = start; i >= 0; i--)
	{
		if (isAscending)
			maxHeap(array, i, length - 1);
		else
			minHeap(array, i, length - 1);
	}

	// ��ʼ������
	for (int i = length-1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		// ���µ����ѽṹ
		if (isAscending)
			maxHeap(array, 0, i - 1);
		else
			minHeap(array, 0, i - 1);
	}
}

// ����һ���Ԫ�����е���С��������������
vector<int> interestNumbers(int N, int nums[])
{
	map<int, int> myMap;
	int min_Dvalue = 0, tmp_Dvalue = 0;
	// step0��������������ö������㷨�����������У�ʱ�临�Ӷ�ΪO(nlogn)
	heapSort(nums, N, true);
	// step1�������е�ֵȫ�����
	if (nums[0] == nums[N - 1])
		return vector<int>((N - 1)*N / 2, (N - 1)*N / 2);

	//step2��ͳ��ÿ�����ֳ��ֵĴ���
	for (int i = 0; i < N; i++)
	{
		if (myMap.find(nums[i]) == myMap.end())
			myMap.insert(make_pair(nums[i], 1));	// ��ʼ���׶�
		else
			myMap.find(nums[i])->second++;
	}
	// step3��������С��ֵ�ĸ���,Ҫ�����ظ�ֵ��û���ظ�ֵ�������
	// ��һ�֣������в������ظ�ֵ
	int first_count, end_count;	// ͳ����Сֵ�����ֵ���ִ���
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
				minDvalue_count = 1;	// �����ָ�С�Ĳ�ֵ��ʱ����������1�����¿�ʼ
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
