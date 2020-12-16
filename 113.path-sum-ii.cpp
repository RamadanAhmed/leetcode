/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;



class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        stack<TreeNode*> visited;
        vector<vector<int>> paths;
        auto curr = root;
        while(!visited.empty() || curr != nullptr){
            vector<int> current_result;
            auto curr_sum = 0;
            while(curr != nullptr){
                if((curr_sum + curr->val) > sum){
                    break;
                }
                current_result.push_back(curr->val);
                curr_sum += curr->val;
                visited.push(curr);
                curr = curr->left;
            }
            if(curr == nullptr && curr_sum == sum){
                paths.emplace_back(current_result);
                current_result.pop_back();
            }
            curr = visited.top();
            visited.pop();
            curr = curr->right;
        }
        return paths;
    }
};
// @lc code=end

