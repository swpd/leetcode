/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *head = root;
        TreeLinkNode *next_head = nullptr;
        while (head) {
            TreeLinkNode *itr = head;
            TreeLinkNode *cur = nullptr;
            while (itr) {
                if (!next_head) {
                    if (itr->left) next_head = itr->left;
                    else if (itr->right) next_head = itr->right;
                }
                if (itr->left) {
                    if (!cur) cur = itr->left;
                    else {
                        cur->next = itr->left;
                        cur = cur->next;
                    }
                }
                if (itr->right) {
                    if (!cur) cur = itr->right;
                    else {
                        cur->next = itr->right;
                        cur = cur->next;
                    }
                }
                itr = itr->next;
            }
            head = next_head;
            next_head = nullptr;
        }
    }
};
