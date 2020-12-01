/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 * Input: nums = [-1,2,1,-4], target = 1
 * [-4,-1,1,2]
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;
class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        auto min_sum = INT_MAX;
        sort(begin(nums), end(nums));
        // must be three numbers
        for(int i = 0; i < nums.size() - 2; ++i) {
            auto start = i + 1;
            auto end = nums.size() - 1;
            while(start < end) {
                auto current_sum = nums[i] + nums[start] + nums[end];
                min_sum = abs(min_sum) > abs(current_sum - target) ? current_sum - target : min_sum;
                if(current_sum > target)
                    --end;
                else
                    ++start;
            }
        }
        return min_sum + target;
    }
};
// @lc code=end
