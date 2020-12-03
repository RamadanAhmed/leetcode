/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> table;
        for(auto c : s) {
            table[c]++;
        }
        int i = 0;
        for(auto c: s) {
            if(table[c] == 1){
                return i;
            }
            ++i;
        }
        return -1;
    }
};
// @lc code=end

