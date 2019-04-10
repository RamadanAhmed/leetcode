/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.81%)
 * Total Accepted:    234K
 * Total Submissions: 521.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for(int i = 1; i <= numRows; i++) {
            std::vector<int> vec;
            int c = 1;
            for(int j = 1; j <= i; j++) {
                vec.push_back(c);
                c = c * (i - j) / j;
            }
            output.push_back(vec);
        }
        return output;
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;

}();
