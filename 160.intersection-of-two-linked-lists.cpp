/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(i   nt x) : val(x), next(NULL) {}
 * };
 */
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        auto countA = 0;
        auto countB = 0;
        while (currA)
        {
            currA = currA->next;
            countA++;
        }
        while (currB)
        {
            currB = currB->next;
            countB++;
        }
        
        auto diff = std::abs(countA - countB);
        if (countA < countB) std::swap(headA, headB);
        for (int i = 0; i < diff; ++i) {
            headA = headA->next;
        }
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

