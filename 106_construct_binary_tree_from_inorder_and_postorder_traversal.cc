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
    TreeNode *buildTree(vector<int> &inorder, int i_start, int i_end, vector<int> &postorder, int p_start, int p_end) {
        if (p_end == p_start) return nullptr;
        int val = postorder[p_end - 1];
        TreeNode *node = new TreeNode(val);
        int idx = -1;
        for (int i = i_start; i < i_end; ++i) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        TreeNode *left = buildTree(inorder, i_start, idx, postorder, p_start, p_start + idx - i_start);
        TreeNode *right = buildTree(inorder, idx + 1, i_end, postorder, p_end - (i_end - idx), p_end - 1);
        node->left = left;
        node->right = right;
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
