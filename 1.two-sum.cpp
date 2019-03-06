/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (41.81%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <map>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        //std::sort(nums.begin(), nums.end());
        std::map<int, int> htable;
        for(int i = 0; i < nums.size(); ++i) {
            auto iter = htable.find(nums[i]);
            if(iter != htable.end()) {
                return {i, iter->second};
            } else {
                htable[target - nums[i]] = i;
            }
        }
        return {};
    }
};
