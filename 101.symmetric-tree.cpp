/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.84%)
 * Total Accepted:    368.6K
 * Total Submissions: 860K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == nullptr || q == nullptr) {
            if(q != nullptr || p != nullptr) {
                return false;
            } else {
                return true;
            }
        }
        if(p->left == nullptr && p->right == nullptr && q->left == nullptr && q->right == nullptr) {
            if(p->val == q->val)
                return true;
            else
                return false;
        }
        if(p->val == q->val) {
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        if(root->left == nullptr || root->right == nullptr) {
            if(root->right != nullptr || root->left != nullptr) {
                return false;
            } else {
                return true;
            }
        }
        return isSameTree(root->left, root->right);
    }
};

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
