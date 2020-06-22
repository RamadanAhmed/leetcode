/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <algorithm>
#include <unordered_map>

static int __ = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        // Solution (O(n) time, O(1) space)
        // Using Hashmap
        int major_number = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            major_number == nums[i] ? count ++: count --; 
            if(count == 0) {
                major_number = nums[i];
                count = 1;
            }
        }
        return major_number;
    }

    int majorityElementNN(vector<int> &nums) {
        // Solution (O(n) time, O(n) space)
        // Using Hashmap
        std::unordered_map<int, int> hash_map;
        for(auto const num : nums) {
            hash_map[num]++;
        }
        for(auto const elem : hash_map) {
            if(elem.second > nums.size() / 2) {
                return elem.first;
            }
        }
        return 0;
    }
    int majorityElementNLogN1(vector<int> &nums) {
        // Solution (O(nlogn) time, O(1) space)
        std::sort(nums.begin(), nums.end());
        int counter = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(counter > (nums.size() / 2))
                return prev;
            else {
                if(nums[i] == prev)
                    counter++;
                else {
                    prev = nums[i];
                    counter = 1;
                }
            }
        }
        return prev;
    }
};
