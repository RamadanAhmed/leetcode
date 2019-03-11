/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.15%)
 * Total Accepted:    248.2K
 * Total Submissions: 772K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        std::string last_word;
        bool space_found = false;
        for (auto &ch : s) {
            if (ch != ' '){
                if (space_found){
                    last_word = ch;
                    space_found = false;
                }
                else {
                    last_word += ch;
                }               
            }
            else {
                space_found = true;
            }
        }
        return last_word.size();
    }
};

