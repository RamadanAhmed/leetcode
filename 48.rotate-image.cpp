/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        unsigned long cols = matrix.size();
        auto rows = cols;

        for(int i = 0 ; i < rows; ++i){
            for(int j = i; j < cols ; ++j){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse
        for(auto &row : matrix) {
            std::reverse(row.begin(), row.end());
        }
    }
};
// @lc code=end

