/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() -1;

        while (i < j)
        {
            std::swap(s[i], s[j]);
            j--;
            i++;
        }
        
    }
};
// @lc code=end

