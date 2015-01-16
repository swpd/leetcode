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
    TreeNode *sortedArrayToBSTHelper(vector<int> &num, int start, int end) {
        int offset = end - start;
        if (offset == 0) return NULL;
        if (offset == 1) return new TreeNode(num[start]);
        int mid = start + offset / 2;
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left_child = sortedArrayToBSTHelper(num, start, mid);
        TreeNode *right_child = sortedArrayToBSTHelper(num, mid + 1, end);
        root->left = left_child;
        root->right = right_child;
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTHelper(num, 0, num.size());
    }
};
