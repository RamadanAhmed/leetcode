/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Check if list is empty or have only one element
    if (head == nullptr || head->next == nullptr)
        return head;
  
    // Initialize previous and current pointers
    auto prev = head;
    auto curr = head->next;
  
    head = curr; // Change head before proceeeding
  
    // Traverse the list
    while (true) {
        auto next = curr->next;
        curr->next = prev; // Change next of
        // current as previous node
  
        // If next nullptr or next is the last node
        if (next == nullptr || next->next == nullptr) {
            prev->next = next;
            break;
        }
  
        // Change next of previous to next next
        prev->next = next->next;
  
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
    return head;
    }
};
// @lc code=end

