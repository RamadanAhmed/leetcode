/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include <string>
using namespace std;

static int __ = []() {
    std::ios::sync_with_stdio(false);
    return 0;
}();

char convertToLiteral(int number) { return char('A' + (number - 1) % 26); }
class Solution {
  public:
    string convertToTitle(int n) {
        string result = "";
        while(n > 0) {
            result.insert(0,1,convertToLiteral(n));
            n = (n - 1) / 26;
        }
        return result;
    }
};
