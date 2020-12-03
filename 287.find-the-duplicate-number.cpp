/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique_nums;
        for(auto num : nums) {
            if(unique_nums.count(num) > 0) return num;
            unique_nums.insert(num);
        }
        return -1;
    }
};
// @lc code=end

