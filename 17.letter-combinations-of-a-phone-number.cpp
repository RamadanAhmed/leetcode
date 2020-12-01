/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.72%)
 * Likes:    3785
 * Dislikes: 405
 * Total Accepted:    598.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    std::unordered_map<char , string> phone {
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return std::vector<string>{};

        std::vector<string> result(1,"");
        for(auto const& digit : digits) {
            auto curr_str = phone.at(digit);
            std::vector<string> tmp;
            for(auto const& ch : curr_str){
                for(auto const& elem : result)
                tmp.push_back(elem + ch);
            }
            std::swap(tmp, result);
        }
        return result;
    }
};
// @lc code=end

