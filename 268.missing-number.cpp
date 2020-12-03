/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <iterator>
#include <numeric>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto curr_sum = std::reduce(std::begin(nums),std::end(nums));
        auto sum = 0;
        for(int i=0;i <nums.size()+1;++i){
            sum += i;
        }
        return sum - curr_sum;
    }
};
// @lc code=end

