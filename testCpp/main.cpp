#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

#include "ListNodeHelper.hpp"

using namespace std;
using namespace leetCode;

ListNode *swapPairs(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return head;
    auto curr = head;
    while (curr != nullptr)
    {
    }
}

int main() {

    auto nodes = construct_from_vector(std::vector<int>{});
    auto head = swapPairs(&nodes[0]);
    print_nodes(head);

    return 0; 
}