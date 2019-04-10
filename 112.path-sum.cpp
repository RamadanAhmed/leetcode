/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (37.15%)
 * Total Accepted:    292.7K
 * Total Submissions: 786.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool tree_sum(TreeNode *root, int target_sum, int previous_sum) {
        int curr_sum = previous_sum + root->val;
		if (!root->left && !root->right) {
			if (curr_sum == target_sum)
				return true;
			else
				return false;
		}
		else if (root->left && root->right)
			return tree_sum(root->right, target_sum, curr_sum) || tree_sum(root->left, target_sum, curr_sum);
		else if (!root->left && root->right)
			return tree_sum(root->right, target_sum, curr_sum);
		else if (!root->right && root->left)
			return tree_sum(root->left, target_sum, curr_sum);
		else return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        return tree_sum(root, sum, 0);
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;

}();
