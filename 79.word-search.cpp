/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
    vector<vector<bool>> visited;
    int maxX = 0;
    int maxY = 0;
  public:
    bool exist(vector<vector<char>> &board, string word) {
        maxX = board.size();
        maxY = board[0].size();
        auto word_index = 0;
        visited = vector<vector<bool>>(maxX, vector<bool>(maxY,false));

        for(int i = 0; i < maxX; ++i) {
            for(int j = 0; j < maxY; ++j) {
                if(word[word_index] == board[i][j] && search_word(i,j,word_index,board,word)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isInBound(int i, int j) {
        return i >= 0 && i < maxX && j >= 0 && j < maxY;
    }
    bool search_word(int i, int j, int word_index, vector<vector<char>> &board, string word) {
        if(word_index == word.size()){
            return true;
        }

        if(!isInBound(i,j) || word[word_index] != board[i][j] || visited[i][j]){
            return false;
        }

        visited[i][j] = true;
        if(search_word(i-1,j,word_index + 1,board,word) ||
           search_word(i+1,j,word_index + 1,board,word) ||
           search_word(i,j+1,word_index + 1,board,word) ||
           search_word(i,j-1,word_index + 1,board,word)) {
               return true;
        }
        visited[i][j] = false;
        return false;
    }
};
// @lc code=end
