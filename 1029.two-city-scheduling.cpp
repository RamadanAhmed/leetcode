/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto half_size = costs.size() / 2;
        nth_element(costs.begin(), costs.begin() + half_size, costs.end(), [](auto elem1, auto elem2){
            return elem1[0] - elem1[1] < elem2[0] - elem2[1];
        });

        return std::accumulate(costs.begin(), costs.begin() + half_size, 0, [](auto elem1, auto elem2){
            return elem1 + elem2[0];
        }) + std::accumulate(costs.begin() + half_size, costs.end(), 0, [](auto elem1, auto elem2){
            return elem1 + elem2[1];
        });
    }
};
// @lc code=end

