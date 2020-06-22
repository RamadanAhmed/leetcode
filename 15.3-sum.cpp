/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.67%)
 * Likes:    6769
 * Dislikes: 803
 * Total Accepted:    900.3K
 * Total Submissions: 3.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        std::sort(nums.begin(), nums.end());
        set<vector<int>> unique;
        for(int i = 0; i < nums.size() - 2; ++i) {
            auto start = i + 1;
            auto end = nums.size() - 1;
            while(start < end) {
                auto sum = nums[start] + nums[end] + nums[i];
                if(sum == 0) {
                    unique.insert(std::vector<int>{nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                } else if(sum > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return std::vector<std::vector<int>>(unique.begin(), unique.end());
    }
};
// @lc code=end

