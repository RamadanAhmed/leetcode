/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.72%)
 * Total Accepted:    357.6K
 * Total Submissions: 878.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> result(digits.size(), 0);
        int carry = 1;
        for (int i = digits.size() -1 ; i >=0 ;i--) {
            int add = digits[i] + carry;
            if (add >= 10) {
                result[i] = add % 10;
                carry = add / 10;
            }
            else {
                result[i] = add;
                carry = 0;
            }
        }
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }
        return result;
    }
};

