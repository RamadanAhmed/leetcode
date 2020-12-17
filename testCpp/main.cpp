#include <algorithm>
#include <optional>
#include <vector>
#include <iterator>
#include <numeric>
#include <stack>

#include "ListNodeHelper.hpp"
#include "TreeNodeHelper.hpp"
using namespace std;
using namespace leetCode;

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    stack<TreeNode *> visited;
    vector<vector<int>> paths;
    auto curr = root;
    vector<int> current_result;
    int curr_sum = 0;
    TreeNode * prev = nullptr;
    while(!visited.empty() || curr != nullptr) {
        while(curr != nullptr) {
            current_result.push_back(curr->val);
            curr_sum += curr->val;
            visited.push(curr);
            curr = curr->left;
        }
        
        curr = visited.top();

        if(curr->left == nullptr && curr->right == nullptr && curr_sum == sum) {
            paths.push_back(current_result);
            prev = curr;
            visited.pop();
            curr_sum -= curr->val;
            current_result.pop_back();
            curr = nullptr;
            continue;
        }
        if(curr->right != nullptr && prev != curr->right) {
            curr = curr->right;
        } else {
            prev = curr;
            visited.pop();
            curr_sum -= curr->val;
            current_result.pop_back();
            curr = nullptr;
        }
        visited.pop();
        curr = curr->right;
    }
    return paths;
}

int main() {

    auto nodes = construct_from_vector(vector<optional<int>>{5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, 5, 1});
    auto vec = pathSum(&nodes[0], 22);

    return 0;
}