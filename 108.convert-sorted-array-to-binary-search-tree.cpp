/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.48%)
 * Total Accepted:    243.4K
 * Total Submissions: 491.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode *sorted_array_bst(vector<int> &nums, const int start, const int end) {
        const auto mid = (end + start) / 2;
        const auto root = new TreeNode(nums[mid]);
        if(start < mid)
            root->left = sorted_array_bst(nums, start, mid - 1);
        if(mid < end)
            root->right = sorted_array_bst(nums, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if(nums.empty())
            return nullptr;
        return sorted_array_bst(nums, 0, nums.size() - 1);
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;

}();

