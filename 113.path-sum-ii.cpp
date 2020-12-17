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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
    stack<TreeNode *> visited;
    vector<vector<int>> paths;
    auto curr = root;
    vector<int> current_result;
    int curr_sum = 0;
    TreeNode * prev = nullptr;
    while(!visited.empty() || curr != nullptr) {
        while(curr != nullptr) {
            current_result.push_back(curr->val);
            curr_sum += curr->val;
            visited.push(curr);
            curr = curr->left;
        }
        
        curr = visited.top();

        if(curr->left == nullptr && curr->right == nullptr && curr_sum == sum) {
            paths.push_back(current_result);
            prev = curr;
            visited.pop();
            curr_sum -= curr->val;
            current_result.pop_back();
            curr = nullptr;
            continue;
        }
        if(curr->right != nullptr && prev != curr->right) {
            curr = curr->right;
        } else {
            prev = curr;
            visited.pop();
            curr_sum -= curr->val;
            current_result.pop_back();
            curr = nullptr;
        }
    }
    return paths;
}
};
// @lc code=end

