/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
  public:
    string tree2str(TreeNode *t) {
        if(t == nullptr) return "";
        if(t->left == nullptr && t->right == nullptr) {
            auto result = ""s;
            result.append(std::to_string(t->val));
            return result;
        }

        if(t->left == nullptr) {
            auto result = ""s;
            result.append(std::to_string(t->val)).append("()").append("(").append(tree2str(t->right)).append(")");
            return result;
        }
        if(t->right == nullptr) {
            auto result = ""s;
            result.append(std::to_string(t->val)).append("(").append(tree2str(t->left)).append(")");
            return result;
        }

        auto result = ""s;
        result.append(std::to_string(t->val)).append("(");
        result.append(tree2str(t->left));
        result.append(")(");
        result.append(tree2str(t->right));
        result.append(")");

        return result;
    }
};
// @lc code=end
