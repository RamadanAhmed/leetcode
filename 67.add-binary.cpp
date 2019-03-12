/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.04%)
 * Total Accepted:    278.9K
 * Total Submissions: 733.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
  public:
    std::pair<char, char> full_adder(char a, char b, char carry_in) {
        int a_ = a - '0';
        int b_ = b - '0';
        int c_in_ = carry_in - '0';
        std::pair<int, int> sum_carry_out;
        sum_carry_out.first = (a_ ^ b_ ^ c_in_) + '0';
        sum_carry_out.second = ((a_ & b_) | ((a_ ^ b_) & c_in_)) + '0';
        return sum_carry_out;
    }

    string addBinary(string a, string b) {
        if(a.size() > b.size()) {
            b = std::string(a.size() - b.size(), '0') + b;
        } else if(a.size() < b.size()) {
            a = std::string(b.size() - a.size(), '0') + a;
        }
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        string result;
        char carry_in = '0';
        for(int i = 0; i < a.size(); i++) {
            auto op_r = full_adder(a[i], b[i], carry_in);
            carry_in = op_r.second;
            result += op_r.first;
        }
        if(carry_in == '1') {
            result += '1';
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
