/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int calPoints(vector<string> &ops) {
        std::vector<int> points;

        for(auto const &op : ops) {
            if(op == "C") {
                points.pop_back();
            } else if(op == "D") {
                auto curr = points.back() * 2;
                points.push_back(curr);
            } else if(op == "+") {
                auto elem2 = points.back();
                points.pop_back();

                auto elem1 = points.back();
                points.push_back(elem2);

                auto curr = elem1 + elem2;
                points.push_back(curr);
            } else {
                auto val = stoi(op);
                points.push_back(val);
            }
        }
        return std::accumulate(points.begin(), points.end(), 0, std::plus<int>{});
    }
};
// @lc code=end
