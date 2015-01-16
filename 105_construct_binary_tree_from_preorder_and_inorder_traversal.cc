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
    TreeNode *buildTree(vector<int> &preorder, int p_start, int p_end, vector<int> &inorder, int i_start, int i_end) {
        if (p_end == p_start) return nullptr;
        int val = preorder[p_start];
        TreeNode *node = new TreeNode(val);
        int idx = -1;
        for (int i = i_start; i < i_end; ++i) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        TreeNode *left = buildTree(preorder, p_start + 1, p_start + 1 + idx - i_start, inorder, i_start, idx);
        TreeNode *right = buildTree(preorder, p_end - (i_end - idx - 1), p_end, inorder, idx + 1, i_end);
        node->left = left;
        node->right = right;
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
