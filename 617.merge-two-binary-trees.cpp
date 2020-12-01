/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr || t2 == nullptr) {
            return t1 != nullptr ? t1 : t2;
        }

        TreeNode* x = new TreeNode(t1->val + t2->val);
        x->left = mergeTrees(t1->left, t2->left);
        x->right = mergeTrees(t1->right, t2->right);
        return x;
    }
};
// @lc code=end

