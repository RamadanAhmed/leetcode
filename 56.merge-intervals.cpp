/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(begin(intervals), end(intervals),[](auto const& interval1, auto const& interval2){
            return interval1[0] < interval2[0];
        });

        std::vector<std::vector<int>> result{intervals[0]};

        for(int i = 1; i< intervals.size(); ++i) {
            if(result.back().at(1) >= intervals[i][0]){
                result.back().at(1) = std::max(intervals[i][1], result.back().at(1));
            }
            else{
                result.emplace_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end

