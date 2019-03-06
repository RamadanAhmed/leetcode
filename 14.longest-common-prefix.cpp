/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.02%)
 * Total Accepted:    414.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        // sort strings
        std::string prefix = "";
        if(!strs.empty()) {
            std::sort(strs.begin(), strs.end());
            // compare first and last element
            auto first = strs.front();
            auto last = strs.back();
            int min = first.size() < last.size() ? first.size() : last.size();
            for(int i = 0; i < min; i++) {
                if(last[i] == first[i]) {
                    prefix.append(1, first[i]);
                } else {
                    break;
                }
            }
        }
        return prefix;
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
