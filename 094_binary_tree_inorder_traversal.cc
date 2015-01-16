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
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) return vector<int>();
        vector<int> ans;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        ans.insert(ans.begin(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
