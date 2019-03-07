/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.92%)
 * Total Accepted:    517K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    void AdvanceIterators(ListNode *&it1, ListNode *&result_tail) {
        ListNode temp(-1);
        temp.next = it1;
        it1 = it1->next;
        result_tail->next = temp.next;
        result_tail = result_tail->next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *result;
        if(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                result = l1;
            } else {
                result = l2;
            }
        } else if(l2 != nullptr) {
            result = l2;
        } else {
            result = l1;
        }

        // initialize list iterators
        ListNode *it1 = l1;
        ListNode *it2 = l2;
        ListNode *result_tail = result;
        while(it1 != nullptr && it2 != nullptr) {
            if(it1->val <= it2->val) {
                AdvanceIterators(it1, result_tail);
            } else {
                AdvanceIterators(it2, result_tail);
            }
        }
        if(it2 != nullptr && result_tail != it2) {
            //AdvanceIterators(it2, result_tail);
            result_tail->next = it2;
        }
        if(it1 != nullptr && result_tail != it1) {
            //AdvanceIterators(it1, result_tail);
            result_tail->next = it1;
        }
        return result;
    }
};
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();
