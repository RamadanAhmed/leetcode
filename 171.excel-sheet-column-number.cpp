/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
#include <string>
using namespace std;
class Solution {
  private:
    int convertToInteger(char elem) { 
        return int(elem - 'A' +1); 
    }

  public:
    int titleToNumber(string s) {
        int result = 0;
        int counter = 0;
        std::for_each(s.rbegin(), s.rend(), [&](const auto c) {
            result += convertToInteger(c) * std::pow(26,counter);
            counter++;
        });
        return result;
    }
};
