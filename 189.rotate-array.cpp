/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 * 
 */
static int __ = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if(k % nums.size()) {
            std::reverse(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.begin() + k % nums.size());
            std::reverse(nums.begin() + k % nums.size(), nums.end());
        }
    }
};
