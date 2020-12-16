/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
class Solution {
public:
void post_order(TreeNode * node, std::vector<std::vector<int>> &result, int level = 0) {
        if (node == nullptr) return;
        if (level >= result.size()) {
            result.push_back({});
        }
        post_order(node->left, result, level + 1);
        post_order(node->right, result, level + 1);
        result[level].emplace_back(node->val);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        post_order(root, result);
        return result;
    }
};
// @lc code=end

