/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.11%)
 * Total Accepted:    610.6K
 * Total Submissions: 2.4M
 * Testcase Example:  '123'
 *
 * Given a 0, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
#include <cmath>

class Solution {
  public:
    int reverse(int x) {
        int reverse = 0;
        while(x != 0) {
            int remain = x % 10;
            if(reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && remain > 7))
                return 0;
            if(reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && remain < -8))
                return 0;
            reverse = reverse * 10 + remain;
            x /= 10;
        }
        return reverse;
    }
};
