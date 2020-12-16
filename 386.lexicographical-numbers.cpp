/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        std::vector<int> result(n);
        std::iota(result.begin(), result.end(),1);
        std::sort(result.begin(), result.end(),[](auto elem1, auto elem2){
            auto elem1_str = std::to_string(elem1);
            auto elem2_str = std::to_string(elem2);
            return elem1_str < elem2_str;
        });
        return result;
    }
};
// @lc code=end

