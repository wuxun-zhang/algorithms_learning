#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Space complexity: constant O()
  // Time complexity: O(n)
  // No assumption that the input string must follow the writing rules of roman
  int romanToInt(string s) {
    unordered_map<char, int> single_num_map{{'I', 1},   {'V', 5},   {'X', 10},
                                            {'L', 50},  {'C', 100}, {'D', 500},
                                            {'M', 1000}};
    // special rules
    unordered_map<string, int> combined_num_map{
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

    int len = s.length();
    // only have single num
    if (len < 2)
      return single_num_map[s[0]];

    // simulate double pointer
    int head = 1, tail = 0;
    int result = 0;
    while (tail < len) {
      string tmp = s.substr(tail, 2);
      if (tmp.length() != 1 &&
          combined_num_map.find(tmp) != combined_num_map.end()) {
        result += combined_num_map[tmp];
        tail += 2;
        head += 2;
      } else {
        result += single_num_map[s[tail]];
        tail++;
        head++;
      }
    }
    return result;
  }

  // O(n), O(1)
  // Assuming that the input string will always meet the requirement of roman
  // writing rules, such as IL/XM is not allowed
  int romanToInt_v2(string s) {
    int len = s.length();
    int result = 0;
    int pre_num = get_value(s[0]);
    int num;
    for (int i = 1; i < len; ++i) {
      num = get_value(s[i]);
      if (pre_num < num) {
        result -= pre_num;
      } else {
        result += pre_num;
      }
      pre_num = num;
    }
    return result + num;
  }

  // get better performance than searching unordered_map/map
  inline int get_value(char a) {
    switch (a) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    }
  }
};

int main() {
  Solution sol;
  string input = "III";
  // while (std::cin >> input) {
  //   std::cout << input << " <-> " << sol.romanToInt_v2(input) << std::endl;
  // }
  std::cout << input << " <-> " << sol.romanToInt(input) << std::endl;
  return 0;
}