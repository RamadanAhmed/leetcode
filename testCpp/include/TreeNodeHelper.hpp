#include <vector>
#include <iostream>
#include <string>

namespace leetCode {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<TreeNode> construct_from_vector(std::vector<int *> const &values) {
    std::vector<TreeNode> nodes(values.size(), TreeNode(0, nullptr, nullptr));

    for(int i = 0; i < values.size() - 1; ++i) {
        if(values[i]) {
            nodes[i].val = *values[i];
            nodes[i].left = (i*2 + 1) < nodes.size() && values[i*2 + 1] ? &nodes[i*2 + 1] : nullptr;
            nodes[i].right = (i*2 + 2) < nodes.size() && values[i*2 + 2] ? &nodes[i*2 + 2] : nullptr;
        }
    }
    return nodes;
}
}  // namespace leetCode