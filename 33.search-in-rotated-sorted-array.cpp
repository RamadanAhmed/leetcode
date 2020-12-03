/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <algorithm>
class Solution {
  public:
    int get_pivot(vector<int> const &nums) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }

    int binary_search(std::vector<int> const &nums, int first_index, int second_index, int target) {
        auto start = first_index;
        auto end = second_index;
        while(start <= end) {
            auto mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int> const &nums, int target) {
        if(nums.empty())
            return -1;
        if(nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        auto pivot_index = get_pivot(nums);
        if(pivot_index == -1) {
            // No rotation
            return binary_search(nums, 0, nums.size() - 1, target);
        }
        if(nums[pivot_index] == target)
            return pivot_index;
        else {
            if(nums.back() < target) {
                // search from rotated part to pivot
                return binary_search(nums, 0, pivot_index, target);

            } else {
                // search from pivot to end
                return binary_search(nums, pivot_index, nums.size() - 1, target);
            }
        }
    }
};
// @lc code=end
