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
    ListNode *merge2Lists(ListNode *fst, ListNode *sec) {
        if (!fst) return sec;
        if (!sec) return fst;
        ListNode dummy(0);
        ListNode *ptr = &dummy;
        while (fst && sec) {
            if (fst->val < sec->val) {
                ptr->next = fst;
                fst = fst->next;
            } else {
                ptr->next = sec;
                sec = sec->next;
            }
            ptr = ptr->next;
        }
        if (fst) ptr->next = fst;
        if (sec) ptr->next = sec;
        return dummy.next;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        vector<ListNode *> ans = lists;
        vector<ListNode *> new_lists;
        while (ans.size() > 1) {
            new_lists.clear();
            int n = ans.size();
            for (int i = 0; i < n / 2; i++) new_lists.push_back(merge2Lists(ans[2 * i], ans[2 * i + 1]));
            if (n % 2 == 1) new_lists.push_back(ans[n - 1]);
            ans = new_lists;
        }
        return ans[0];
    }
};
