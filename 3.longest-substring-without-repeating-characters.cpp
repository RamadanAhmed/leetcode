/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.54%)
 * Likes:    9206
 * Dislikes: 558
 * Total Accepted:    1.5M
 * Total Submissions: 5.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> window;
        size_t largest_substr = 0;
        auto start_substr = 0;
        auto end_substr = 0;
        while(end_substr < s.length()) {
            if(window.find(s.at(end_substr)) == window.end()) {
                window.insert(s.at(end_substr++));
                largest_substr = std::max(largest_substr, window.size());
            } else {
                window.erase(s.at(start_substr++));
            }
        }
        return largest_substr;
    }
};
// @lc code=end
