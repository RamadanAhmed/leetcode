/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        std::vector<std::vector<int>> result;
        auto rows = M.size();
        auto cols = M.at(0).size();
        for(int i = 0; i < rows; ++i) {
            result.emplace_back(std::vector<int>(cols, 0));
        }

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                auto sum = 0;
                auto count = 0;
                for(int r = i - 1; r <= (i + 1); ++r) {
                    for(int c = j - 1; c <= (j + 1); ++c) {
                        if(r < rows && r >= 0 && c < cols && c >= 0) {
                            sum = sum + M[r][c];
                            ++count;
                        }
                    }
                }
                result[i][j] = (sum / count);
            }
        }
        return result;
    }
};
// @lc code=end
