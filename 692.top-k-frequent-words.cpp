/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
// @lc code=start
class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        std::unordered_map<string, int> table;
        for(auto const &word : words) {
            table[word]++;
        }

        std::vector<pair<string, int>> top_k_pair(k);
        std::partial_sort_copy(table.begin(), table.end(), top_k_pair.begin(), top_k_pair.end(), [](auto const &elem1, auto const &elem2) {
            return elem1.second == elem2.second ? elem1.first < elem2.first : elem1.second > elem2.second;
        });

        std::vector<string> top_k;
        std::transform(top_k_pair.begin(), top_k_pair.end(), std::back_inserter(top_k), [](auto const &elem) { return elem.first; });

        return top_k;
    }
};
// @lc code=end
