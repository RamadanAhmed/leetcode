/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
    ListNode* reverse(ListNode * const head) {
        ListNode* prev = nullptr;
        ListNode* follow = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            follow = current;
            current = current->next;
            follow->next = prev;
            prev = follow;
        }
        return prev;
    }
public:
    bool hasCycle(ListNode *head) {
        /*
         * Second Solution:
         * create 2 pointer, 
         * P2 with 2 steps and P1 with only one step
         * if there is a cycle, eventually P1 & P2 catches each others
         * (due to one is moving faster than the other) 
         */
        if(!head || !head->next) return false;
        ListNode* p1 = head; 
        ListNode* p2 = head;

        while (p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) return true;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        // First Solution - Reverse the Linked List
        return head && head->next && reverse(head) == head;
    }
};
