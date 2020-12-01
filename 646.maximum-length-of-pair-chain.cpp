/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](auto const& elem1, auto const& elem2){
            return elem1[1] < elem2[1]; 
        });

        auto last = pairs[0][1];
        auto count = 1;
        for(auto const& elem : pairs) {
            if(elem[0] > last) {
                last = elem[1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

