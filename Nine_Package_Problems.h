#pragma once

#include<vector>
#include<algorithm>
using namespace std;

// N：物品数量
// C：每件物品对应的重量
// W：每件物品对应的价值
// V：背包的容量
// 返回该背包所放物品的最大价值
int zero_one_pack(const int N, int C[], int W[], const int V)
{
	vector<vector<int> > maxVal(N+1);
	for (int i = 0; i <= N; i++)
		maxVal[i].resize(V + 1);
	// 初始化二维数组
	for (int i = 0; i <= N; i++)
		maxVal[i][0] = 0;
	for (int j = 0; j <= V; j++)
		maxVal[0][j] = 0;
	// 开始求解（动态规划）
	for (int i = 1; i <= N; i++)
	{
		for (int j = C[i]; j <= V; j++)
		{
			maxVal[i][j] = max(maxVal[i - 1][j], maxVal[i - 1][j - C[i]] + W[i]);
		}
	}
	return maxVal[N][V];
}

int zero_one_pack_optimal(const int N, int C[], int W[], const int V)
{
	vector<int> maxVal(V + 1);
	// 初始化二维数组
	for (int i = 0; i <= V; i++)
		maxVal[i] = 0;

	// 开始求解（动态规划）
	for (int i = 0; i < N; i++)
	{
		for (int j = V; j >= C[i]; j--)
		{
			maxVal[j] = max(maxVal[j], maxVal[j - C[i]] + W[i]);
		}
	}
	return maxVal[V];
}
