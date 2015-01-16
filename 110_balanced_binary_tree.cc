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
    bool isBalanced(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        int left_height, right_height;
        bool left_is_balanced = isBalanced(root->left, left_height);
        bool right_is_balanced = isBalanced(root->right, right_height);
        height = left_height > right_height ? left_height + 1 : right_height + 1;
        if (!left_is_balanced || !right_is_balanced) return false;
        if (left_height + 1 < right_height || right_height + 1 < left_height) return false;
        return true;
    }
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalanced(root, height);
    }
};
