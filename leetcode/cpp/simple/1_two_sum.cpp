#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/// There is only one answer corresponding to each inputs

class Solution {
public:
    // Simplest solution
    // traverse all elements, time complxity is almost O(N*N)
    // space complexity O(1)
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ret;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums.at(i) + nums.at(j) == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }

    /// Not correct
    vector<int> twoSum_v2(vector<int> &nums, int target) {
        vector<int> ret;
        int len = nums.size();

        // sort inputs numbers
        // time complexity is O(NlogN)
        // but it will destroy the original order of input numbers
        sort(nums.begin(), nums.end());

        // Time complexity is O(N)
        int i = 0, j = len - 1;
        while(i <= j) {
            if (nums.at(i) + nums.at(j) < target) {
                ++i;
            } else if (nums.at(i) + nums.at(j) > target) {
                --j;
            } else {
                ret.push_back(i);
                ret.push_back(j);
                // The same element cannot be used twice.
                ++i;
                --j;
            }
        }
        return ret;
    }

    // time complexity O(N)
    // space complexity O(N)
    vector<int> twoSum_v3(vector<int> &nums, int target) {
        vector<int> ret;
        ret.reserve(2);
        int len = nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < len; ++i) {
            map.insert({nums.at(i), i});
        }

        for (int i = 0; i < len; ++j) {
            if (map.count(target - nums.at(i)) && i != map[target - nums.at(i)]) {
                ret.push_back(i);
                ret.push_back(map[target - nums.at(i)]);
                break;
            }
        }
        return ret;
    }

    // time complexity O(N)
    // space complexity O(N)
    vector<int> twoSum_v4(vector<int> &nums, int target) {
        vector<int> ret;
        unordered_map<int, int> map;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (map.count(target - nums.at(i)) && i != map[target - nums.at(i)]) {
                ret.push_back(map[target - nums.at(i)]);
                ret.push_back(i);
                break;
            }
            map.insert({nums.at(i), i});
        }
        return ret;
    }

};