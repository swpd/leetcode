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
        if (!root->left) return;
        TreeLinkNode *head = root;
        while (head->left) {
            TreeLinkNode *itr = head;
            while (itr) {
                itr->left->next = itr->right;
                if (itr->next) itr->right->next = itr->next->left;
                itr = itr->next;
            }
            head = head->left;
        }
    }
};
