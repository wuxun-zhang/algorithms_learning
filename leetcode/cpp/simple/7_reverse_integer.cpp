#include <iostream>
#include <deque>
#include <numeric>
#include <limits>
using namespace std;

/// Need take care of some special cases:
///  1. input is 0
///  2. inputs is -2^31
///  3. The accumulated number should use unsigned long type in case for overflow

class Solution {
public:
    /// Using stack based method
    /// first in last out
    int reverse(int x) {
        deque<int> digits;
        // special case 1: 
        if (x == 0) return 0;
        // special case 2: inputs is -2^31
        if (x == std::numeric_limits<int>::min()) return 0;
        bool is_negative = false;
        if (x < 0) {
            x = -x; // int can not repesent some integers
            is_negative = true;
        }
        
        int a = x % 10;
        digits.push_back(a);

        int b = x / 10;
        while(b != 0) {
            x = b;

            a = x % 10;
            digits.push_back(a);
            b = x / 10;
        }

        unsigned long new_num = 0;
        int len = digits.size();
        for (int i = 0; i < len; ++i) {
            int j = digits.front();
            // std::cout << "j = " << j << std::endl;
            digits.pop_front();
            if (i == 0 && j == 0) continue;
            new_num = new_num * 10 + j;
            // std::cout << "new_num = " << new_num << std::endl;
        }

        /// whether greater than max value of int
        if (new_num > std::numeric_limits<int>::max())
            return 0;
        /// whether less than min value of int
        if (is_negative && -new_num < std::numeric_limits<int>::min())
            return 0;
        if (is_negative)
            new_num = -new_num;
        return new_num;
    }

    // No stack method
    // The key point here is how to determine the overflow (see line 74 and 77)
    int reverse_v2(int x) {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();

        if (x == 0) return 0;
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            // res is large than MAX_INT / 10 or
            // equal to MAX_INT / 10 and the last digit is larger than 7 (2^31-1=...7)
            if (res > max_int / 10 || (res == max_int / 10 && pop > 7)) return 0;
            // res is less than MIN_INT / 10 or
            // equal to MIN_INT / 10 and the last digit is less than -8 (-2^31=-...8)
            if (res < min_int / 10 || (res == min_int / 10 && pop < -8)) return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int x = -2147;
    int y = sol.reverse_v2(x);
    // std::cout << "std::numeric_limits<int>::min() = " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "y = " << y << std::endl;
    return -1;
}