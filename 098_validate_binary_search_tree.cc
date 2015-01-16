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
    bool isValidBST(TreeNode *root, int low, int high) {
        if (!root) return true;
        return (root->val > low && root->val < high
            && isValidBST(root->left, low, root->val)
            && isValidBST(root->right, root->val, high));
    }
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
