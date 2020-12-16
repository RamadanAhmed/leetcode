/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> visited;
        auto curr = root;
        TreeNode* prev = nullptr;
        while(!visited.empty() || curr != nullptr){
            while(curr != nullptr){
                visited.push(curr);
                curr = curr->left;
            }
            curr = visited.top();
            visited.pop();
            if(prev != nullptr && prev->val >= curr->val){
                return false;
            }
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};
// @lc code=end

