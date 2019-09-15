/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */
static int __ = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
  public:
    int trailingZeroes(int n) {
        // Check if number is greater than five
        int result = 0;
        const int limit = std::log(n) / std::log(5);
        for(int i = 0; i < limit; ++i) {
            result += n / (std::pow(5, i + 1));
        }
        return result;
    }
};
