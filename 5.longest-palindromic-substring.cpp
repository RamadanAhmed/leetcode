/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.71%)
 * Likes:    6728
 * Dislikes: 530
 * Total Accepted:    926.5K
 * Total Submissions: 3.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string longestPalindrome(string s) {
         if (s.empty() ) return "";
         if (s.length() < 2) return s;
        auto start = 0, end = 0;
        for(int i = 0; i < s.length(); ++i) {
            auto len1 = expandFromMiddle(s, i, i);
            auto len2 = expandFromMiddle(s, i, i + 1);
            auto len = std::max(len2, len1);
            if(len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        std::cout << start << " " << end;
        return s.substr(start, end-start + 1);
    }

    int expandFromMiddle(string s, int left, int right) {
        int l = left, r = right;
        while(l >= 0 && r < s.length() && s.at(l) == s.at(r)) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};
// @lc code=end
