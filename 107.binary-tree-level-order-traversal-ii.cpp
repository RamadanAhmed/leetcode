/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.82%)
 * Total Accepted:    212.7K
 * Total Submissions: 463.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> result;
        post_order(root, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
};
