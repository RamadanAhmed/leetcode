/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    std::vector<std::pair<int, std::string>> integer_to_roman {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},  
        {50, "L"},
        {40, "XL"},           
        {10,"X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };
    string intToRoman(int num) {
        auto s = "";
        for(auto &[value, r_literals] : integer_to_roman){
            auto freq = num / value;
            while(freq > 0){
                s += r_literals;
                --freq;
            }
            num = num % value;
        }
    }
};
// @lc code=end

