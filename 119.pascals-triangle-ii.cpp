/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (42.31%)
 * Total Accepted:    189.5K
 * Total Submissions: 447K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> vec;
        long long c = 1;
        for(int j = 1; j <= rowIndex + 1; j++) {
            vec.push_back(c);
            c = c * (rowIndex + 1 - j) / j;
        }
        return vec;
    }
};
