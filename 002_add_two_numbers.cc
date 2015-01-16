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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *l3 = NULL;
        ListNode *itr1 = l1, *itr2 = l2, *itr3 = NULL;
        int carry = 0;
        while (itr1 && itr2) {
            int sum = itr1->val + itr2->val + carry;
            carry = 0;
            if (sum >= 10) {
                sum %= 10;
                carry = 1;
            }
            if (!l3) {
                l3 = new ListNode(sum);
                itr3 = l3;
            } else {
                itr3->next = new ListNode(sum);
                itr3 = itr3->next;
            }
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        if (!itr1) {
            while (itr2) {
                int sum = itr2->val + carry;
                carry = 0;
                if (sum >= 10) {
                    sum %= 10;
                    carry = 1;
                }
                itr3->next = new ListNode(sum);
                itr3 = itr3->next;
                itr2 = itr2->next;
            }
        }
        if (!itr2) {
            while (itr1) {
                int sum = itr1->val + carry;
                carry = 0;
                if (sum >= 10) {
                    sum %= 10;
                    carry = 1;
                }
                itr3->next = new ListNode(sum);
                itr3 = itr3->next;
                itr1 = itr1->next;
            }
        }
        if (carry) itr3->next = new ListNode(1);
        return l3;
    }
};
