/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.62%)
 * Total Accepted:    261.7K
 * Total Submissions: 660.5K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
  public:
    string countAndSay(int n) {
        if(n-- == 1)
            return "1";
        string cur, pre = "11";
        while(--n) {
            int count = 1, i;
            char c = pre[0];
            for(i = 1; i < pre.length(); i++) {
                if(pre[i] == c)
                    count++;
                else {
                    cur += char('0' + count);
                    cur += c;
                    c = pre[i];
                    count = 1;
                }
            }
            if(i == pre.length()) {
                cur += char('0' + count);
                cur += c;
            }
            pre = cur;
            cur = "";
        }
        return pre;
    }
};

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
