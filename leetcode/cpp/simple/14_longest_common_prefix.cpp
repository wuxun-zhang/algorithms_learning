#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxCommonPrefixLen(string &a, string &b) {
  int len = min(a.length(), b.length());
  int max_len = 0;
  for (int i = 0; i < len; ++i) {
    if (a[i] == b[i]) {
      max_len++;
    } else {
      break;
    }
  }
  return max_len;
}

// O(mn), O(1)
string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty())
    return "";
  // just return when there is only one string
  if (strs.size() < 2)
    return strs[0];
  int max_len = maxCommonPrefixLen(strs[0], strs[1]);
  int str_size = strs.size();
  for (int i = 2; i < str_size; ++i) {
    string tmp = strs[i - 2].substr(0, max_len);
    max_len = maxCommonPrefixLen(tmp, strs[i]);
    // just return "" when there is no common prefix between any two strings
    if (max_len == 0)
      return "";
  }
  return strs[0].substr(0, max_len);
}

// O(mn), O(1)
string longestCommonPrefix_v2(vector<string> &strs) {
  if (strs.empty())
    return "";

  int len = strs[0].size();
  for (int i = 0; i < len; ++i) {
    char c = strs[0][i];
    for (int j = 1; j < strs.size(); ++j) {
      if (i == strs[j].size() || c != strs[j][i])
        return strs[0].substr(0, i);
    }
  }
}

// Divide and conqur
string commomPrefix(string &s1, string &s2) {
  int len = min(s1.size(), s2.size());
  for (int i = 0; i < len; ++i) {
    if (s1[i] != s2[i])
      return s1.substr(0, i);
  }
  return s1.substr(0, len);
}
string longestCommonPrefix(vector<string> &strs, int start, int end) {
  if (start == end) {
    return strs[start];
  } else {
    int mid = (start + end) / 2;
    // recursively call this function until we get the single string
    string lcpLeft = longestCommonPrefix(strs, start, mid);
    string lcpRight = longestCommonPrefix(strs, mid + 1, end);
    // get the common prefix for these two strings
    return commomPrefix(lcpLeft, lcpRight);
  }
}
string longestCommonPrefix_v3(vector<string> &strs) {
  if (strs.empty())
    return "";
  if (strs.size() == 1)
    return strs[0];

  int start = 0, end = strs.size() - 1;
  return longestCommonPrefix(strs, start, end);
}

int main() {
  vector<string> inputs = {"flower", "flog", "fly"};
  cout << longestCommonPrefix_v3(inputs) << endl;
  return 1;
}
