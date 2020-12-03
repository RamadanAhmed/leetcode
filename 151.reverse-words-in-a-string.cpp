/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <iostream>
#include <utility>
#include <memory>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    std::vector<std::string> split_string(std::string const &s) {
        std::vector<std::string> words;
        istringstream iss(s);
        std::vector<std::string> un_santized_words{istream_iterator<string>{iss}, istream_iterator<string>{}};
        for(auto const& w : un_santized_words){
            if(!w.empty()){
                words.emplace_back(w);
            }
        }
        return words;
    }
    string reverseWords(string s) {
        // split words using spaces
        auto words = split_string(s);
        // use std::reverse
        std::reverse(std::begin(words), std::end(words));
        std::string output;
        std::for_each(words.begin(), words.end() -1, [&output](auto const& word){
            output.append(word).append(" ");
        });
        output.append(words[words.size() - 1]);
        return output;
    }
};
// @lc code=end
