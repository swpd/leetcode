/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *itr = head;
        while (itr) {
            RandomListNode *node = new RandomListNode(itr->label);
            node->next = itr->next;
            itr->next = node;
            itr = itr->next->next;
        }
        itr = head;
        while (itr) {
            if (itr->random) itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        itr = head;
        RandomListNode dummy(0);
        RandomListNode *dummy_ptr = &dummy;
        RandomListNode *new_itr = dummy_ptr;
        while (itr) {
            new_itr->next = itr->next;
            new_itr = new_itr->next;
            itr->next = itr->next->next;
            itr = itr->next;
        }
        return dummy_ptr->next;
    }
};
