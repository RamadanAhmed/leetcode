/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = std::to_string(n);
        return next_permutation(s.begin(), s.end()) && stol(s) <= INT_MAX ? stoi(s) : -1;
    }
};
// @lc code=end

