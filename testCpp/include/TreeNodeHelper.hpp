#include <vector>
#include <iostream>
#include <string>
#include <optional>

namespace leetCode {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<TreeNode> construct_from_vector(std::vector<std::optional<int>> const &values) {
    std::vector<TreeNode> nodes(values.size(), TreeNode(0, nullptr, nullptr));

    for(int i = 0; i < values.size(); ++i) {
        if(values[i].has_value()) {
            nodes[i].val = values[i].value();
            nodes[i].left = (i * 2 + 1) < nodes.size() && values[i * 2 + 1].has_value() ? &nodes[i * 2 + 1] : nullptr;
            nodes[i].right = (i * 2 + 2) < nodes.size() && values[i * 2 + 2].has_value() ? &nodes[i * 2 + 2] : nullptr;
        }
    }
    return nodes;
}
}  // namespace leetCode