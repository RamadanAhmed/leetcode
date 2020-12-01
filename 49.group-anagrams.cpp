/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    std::unordered_map<string, std::vector<string>> table;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for(auto const& str_elem : strs) {
            auto temp = str_elem;
            std::sort(temp.begin(), temp.end());
            if(table.find(temp) != table.end()) {
                table.at(temp).emplace_back(str_elem);
            }
            else {
                table[temp] = std::vector<string> {str_elem};
            }
        }
        for(auto const& [key, value] : table) {
            result.emplace_back(value);
        }
        return result;
    }
};
// @lc code=end

