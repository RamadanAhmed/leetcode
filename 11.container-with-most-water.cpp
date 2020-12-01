/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
  public:
    int maxArea(vector<int> &height) {
        auto max_area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            auto curr_area = std::min(height[j],height[i]) * (j-i);
            max_area = std::max(max_area,curr_area);
            if(height[i] <= height[j]) ++i;
            else --j;
        }
        return max_area;
    }
};
// @lc code=end
