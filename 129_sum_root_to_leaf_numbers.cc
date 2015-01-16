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
    void sumNumbers(TreeNode *root, int current, int &sum) {
        current = current * 10 + root->val;
        if (!root->left && !root->right) {
            sum += current;
        }
        if (root->left) {
            sumNumbers(root->left, current, sum);
        }
        if (root->right) {
            sumNumbers(root->right, current, sum);
        }
    }
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
};
