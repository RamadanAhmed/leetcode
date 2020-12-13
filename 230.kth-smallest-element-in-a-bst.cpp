/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
using namespace std;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> visited;
        auto curr = root;
        while (curr != nullptr || !visited.empty())
        {
            // traverse left
            while (curr != nullptr){
                visited.push(curr);
                curr = curr->left;
            }
            curr = visited.top();
            visited.pop();
            // Check queue size
            if(--k == 0){
                // return kth smallest
                return curr->val;
            }
            // traverse right
            curr = curr->right;
        }
        return 0;
    }
};
// @lc code=end

