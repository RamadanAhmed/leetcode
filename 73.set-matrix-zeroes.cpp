/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zerosPlaces;
        auto column = matrix.at(0).size();
        auto row = matrix.size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j) {
                if(matrix[i][j] == 0){
                    zerosPlaces.emplace_back(make_pair(i,j));
                }
            }
        }

        for (auto [x,y] : zerosPlaces){
            for(int i = 0; i < column; ++i){
                matrix[x][i] = 0;
            }
            for(int i = 0; i < row; ++i){
                matrix[i][y] = 0;
            }
        }
    }
};
// @lc code=end

