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
    void pathSum(TreeNode *root, int sum, vector<int> current, vector<vector<int> > &ans) {
        if (!root) return;
        current.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            ans.push_back(current);
            return;
        }
        pathSum(root->left, sum - root->val, current, ans);
        pathSum(root->right, sum - root->val, current, ans);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> current;
        pathSum(root, sum, current, ans);
        return ans;
    }
};
