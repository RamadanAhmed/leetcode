/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), std::greater<int>());
        return nums[k-1];
    }
};
// @lc code=end

