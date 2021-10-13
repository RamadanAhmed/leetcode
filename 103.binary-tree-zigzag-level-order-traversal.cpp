/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (46.69%)
 * Likes:    2848
 * Dislikes: 114
 * Total Accepted:    447.8K
 * Total Submissions: 904.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
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
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        std::queue<TreeNode*> q;
        vector<vector<int>> result;
        
        q.push(root);

        auto alternate = false;
        while (!q.empty()) {
            auto q_sz = q.size();
            vector<int> temp(q_sz);
            for(int i = 0; i < q_sz; ++i){
                auto elem = q.front();
                temp[i] = elem->val;
                q.pop();
                if(elem->left != nullptr) q.push(elem->left);
                if(elem->right != nullptr) q.push(elem->right);
                
            }

            if(alternate) {
                reverse(temp.begin(), temp.end());
            }
            result.push_back(temp);
            alternate = !alternate;
        }
        return result;
    }
};
// @lc code=end

