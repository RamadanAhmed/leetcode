/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        auto it1 = 0;
        auto it2 = 1;
        while(it2 < nums.size()) {
            if (nums[it1] != 0) {
                ++it1;
                ++it2;
            }
            else if(nums[it1] == 0 && nums[it2] != nums[it1]) {
                std::swap(nums[it1], nums[it2]);
                ++it1;
                ++it2;
            } else {
                ++it2;
            }
        }
    }
};
// @lc code=end
