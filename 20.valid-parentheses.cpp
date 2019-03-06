/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.93%)
 * Total Accepted:    523K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
  public:
    std::map<char, char> closingtoOpen = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    bool isClose(char c) { return c == ')' || c == '}' || c == ']'; }
    bool isOpen(char c) { return c == '(' || c == '{' || c == '['; }
    bool isValid(std::string s) {
        if(s.empty()) {
            return true;
        }
        std::stack<char> parentheses;
        for(auto &ch : s) {
            if(isOpen(ch)) {
                parentheses.push(ch);
            } else if(isClose(ch) && !parentheses.empty() && ch == closingtoOpen.at(parentheses.top())) {
                parentheses.pop();
            } else {
                return false;
            }
        }
        return parentheses.empty();
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();

