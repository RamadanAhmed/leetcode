#include <vector>
#include <iostream>

namespace leetCode {
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<ListNode> construct_from_vector(std::vector<int> const& values){
    std::vector<ListNode> nodes(values.size(),ListNode(0));

    for(int i = 0; i < nodes.size() - 1; ++i) {
        nodes[i].next = &nodes[i+1];
        nodes[i].val = values[i];
    }
    nodes[nodes.size() - 1].val = values[nodes.size() - 1];
    return nodes;
}

void print_nodes(ListNode * head){
    auto curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ---> ";
    }
    std::cout << "null" << std::endl;
}
}