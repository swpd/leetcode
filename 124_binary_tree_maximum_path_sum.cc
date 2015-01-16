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
    int helper(TreeNode *root, int &max_with_root) {
        int left_with_root = 0, right_with_root = 0;
        int left, right;
        int max_path = root->val;
        max_with_root = root->val;
        int path_with_root = root->val;
        if (root->left) {
            left = helper(root->left, left_with_root);
            path_with_root += max(0, left_with_root);
            max_path = max(left, max_path);
        }
        if (root->right) {
            right = helper(root->right, right_with_root);
            path_with_root += max(0, right_with_root);
            max_path = max(right, max_path);
        }
        max_with_root = max_with_root + max(max(left_with_root, right_with_root), 0);
        return max(path_with_root, max_path);
    }
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int max_with_root;
        return helper(root, max_with_root);
    }
};
