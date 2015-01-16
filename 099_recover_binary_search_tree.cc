/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (!root) return;
        TreeNode *node1 = NULL;
        TreeNode *node2 = NULL;
        // find swapped nodes, iterative inorder traverse
        stack<TreeNode *> stk;
        TreeNode *pre = NULL;
        TreeNode *node = root;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                if (pre) {
                    if (pre->val > node->val) {
                        if (!node1) node1 = pre;
                        node2 = node;
                    }
                }
                pre = node;
                node = node->right;
            }
        }
        swap(node1->val, node2->val);
    }
};
