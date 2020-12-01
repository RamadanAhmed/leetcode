/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        auto org_count = 0;
        auto curr_count = 0;
        std::unordered_set<int> unique;
        for(int i = 0; i < nums.size(); ++i) {
            org_count += i + 1;
            curr_count += nums[i];
            unique.insert(nums[i]);
        }

        auto unique_count = std::accumulate(unique.begin(), unique.end(), 0, std::plus<int>{});

        auto duplicate = curr_count - unique_count;

        return std::vector<int>{duplicate, org_count - curr_count + duplicate};
    }
};
// @lc code=end
