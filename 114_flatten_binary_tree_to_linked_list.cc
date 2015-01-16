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
    void flatten_helper(TreeNode *root, TreeNode *&last) {
        if (!root) {
            last = NULL;
            return;
        }
        if (!root->left && !root->right) {
            last = root;
            return;
        }
        
        TreeNode *left_last, *right_last;
        flatten_helper(root->left, left_last);
        flatten_helper(root->right, right_last);
        TreeNode *flattened_right = root->right;
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
            left_last->right = flattened_right;
        }
        if (flattened_right) last = right_last;
        else last = left_last;
    }
    void flatten(TreeNode *root) {
        TreeNode *last;
        flatten_helper(root, last);
    }
};
