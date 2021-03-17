#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct solution {
    // O(n), O(n)
    // using hashmap, unordered_map<num, count>
    int majorityElement_v1(vector<int> &nums) {
        std::unordered_map<int, int> count;
        int majority = 0, cnt = 0;
        for (const auto &n : nums) {
            ++count[n];
            // recored the majority during the iteration
            if (count[n] > cnt) {
                majority = n;
                cnt = count[n];
            }
        }
        return majority;
    }

    // assuming that there always has majority number
    int majorityElement_v2(vector<int> &nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0];
        // sort the input numbers
        std::stable_sort(nums.begin(), nums.end());
        int len = nums.size();
        int pre = nums[0];
        int accum = 1;
        for (int i = 1; i < len; ++i) {
            int cur = nums[i];
            if (pre == cur) {
                accum++;
            } else {
                accum = 1;
            }
            // need to consider the boundary
            if (accum >= int(len / 2.0 + 0.5)) return cur;
            pre = cur;
        }
        return 0;
    }

    // conqur and divide
    // concern case: {2,1,2,1, 2,1,2,3}
    int majorityElement_v3(vector<int> &nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0];

        int start = 0, end = nums.size() - 1;
        return recurse(nums, start, end);
    }

    int recurse(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];
        else {
            int mid = (start + end) / 2;
            int leftVal = recurse(nums, start, mid);
            int rightVal = recurse(nums, mid + 1, end);
            if (count_in_range(nums, leftVal, start, end)
                    > (end - start + 1) / 2)
                return leftVal;
            if (count_in_range(nums, rightVal, start, end)
                    > (end - start + 1) / 2)
                return rightVal;
            return -1;
        }
    }
    int count_in_range(vector<int> &nums, int target, int start, int end) {
        int cnt = 0;
        for (int i = start; i <= end; ++i)
            if (nums[i] == target) ++cnt;
        return cnt;
    }

    // only traverse once
    // Simplest!!!
    /// boyer-moores voting algorithms
    int majorityElement_v4(vector<int> &nums) {
        int count = 0;
        int candidate = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    solution sol;
    vector<int> input {2, 1, 2, 1, 2, 1, 2, 3};
    cout << sol.majorityElement_v4(input) << endl;
    return 1;
}
