/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.74%)
 * Likes:    8168
 * Dislikes: 2080
 * Total Accepted:    1.4M
 * Total Submissions: 4.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        auto temp = head;
        auto result = 0;
        auto p1 = l1;
        auto p2 = l2;
        auto carry = 0;
        while (p1 != nullptr || p2 != nullptr || carry > 0)
        {
            auto x = p1 != nullptr ? p1->val : 0;
            auto y = p2 != nullptr ? p2->val : 0;
            result = x + y + carry;
            temp->next = new ListNode(result % 10);
            carry = result / 10;
            if(p1 != nullptr) p1 = p1->next;
            if(p2 != nullptr) p2 = p2->next;
            temp = temp->next;
        }
        return head->next;
    }
};
// @lc code=end

