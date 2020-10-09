#include <iostream>
#include <numeric>
#include <limits>
using namespace std;

class Solution {
public:
    // space complexity: O(1)
    // time complexity: O()
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        // int max_int = std::numeric_limits<int>::max();
        unsigned long res = 0;
        int ref_x = x;
        while (x != 0) {
            int pop = x % 10;
            // if(res > max_int / 10 || (res == max_int / 10 && pop > 7)) return false;
            res = res * 10 + pop;
            x /= 10;
        }

        // if the reversed number equals to the original number,
        // then this number should be palindrome.
        if (ref_x == res) return true;
        return false;
    }

    bool isPalindrome_v2(int x) {
        // special case
        if (x < 0) return 0;
        int div = 1;
        // find the biggest divide number to make x/div equal to integer
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            // The head digit
            int left = x / div;
            // The tail digit
            int right = x % 10;
            // std::cout << "left is " << left << std::endl;
            // std::cout << "right is " << right << std::endl;
            // if head digit doesn't equal to tail digit, return false
            if (left != right) return false;
            // remove head and tail digit
            x = (x % div) / 10;
            // update division (removed two digits, so we need divide by 100)
            div /= 100;
        }
        return true;
    }

    // Time complexity: O(log10N)
    // Space complexity: O(1)
    bool isPalindrome_v3(int x) {
      // special case 1: negative number must not be palidrome number
      // special case 2: the last digit is 0, only x=0 is palidrome number,
      // otherwise not
      if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

      int revertedNum = 0;
      // Only compare half of the digits
      while (x > revertedNum) {
        revertedNum = revertedNum * 10 + x % 10;
        x /= 10;
      }
      // case 1: the number of digits is even
      // case 2: the number of digits is odd
      return (x == revertedNum || x == revertedNum / 10);
    }
};

int main() {
    Solution sol;
    int x = -1001;
    bool flag = sol.isPalindrome_v3(x);
    std::cout << (flag ? string("yes, it's palindrome.") : string("No, it's not palindrome.")) << std::endl;
    return 0;
}