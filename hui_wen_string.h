#pragma once

#include<string>
#include<algorithm>
#include<assert.h>


int hui_wen_string_construction(std::string s)
{
	if (s.size() < 1 || s.size() > 1000)
		return -1;

	std::string s1(s.rbegin(), s.rend());	// ����s�������ַ���
	vector<vector<int> > maxLen(s.size() + 1);	// �����άvector����
	//maxLen.resize(s.size() + 1);
	for (int i = 0; i <= s.size(); i++)
	{
		maxLen[i].resize(s1.size() + 1);
	}

	for (int i = 0; i <= s.size(); i++)
	{
		maxLen[i][0] = 0;
		maxLen[0][i] = 0;
	}
	//���ö�̬�滮˼��������
	for (int m = 1; m <= s.size(); m++)
	{
		for (int n = 1; n <= s1.size(); n++)
		{
			if (s[m - 1] == s1[n - 1])
				maxLen[m][n] = 1 + maxLen[m - 1][n - 1];
			else
				maxLen[m][n] = max(maxLen[m][n - 1], maxLen[m - 1][n]);
		}
	}
	return (s.size() - maxLen[s.size()][s1.size()]);
}