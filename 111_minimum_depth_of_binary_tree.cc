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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int min_left = minDepth(root->left);
        int min_right = minDepth(root->right);
        if (min_left == 0) return min_right + 1;
        if (min_right == 0) return min_left + 1;
        int depth = min_left < min_right ? min_left + 1 : min_right + 1;
        return depth;
    }
};
