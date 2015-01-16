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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == nullptr) return ans;
        queue<int> levels;
        queue<TreeNode *> nodes;
        int level = 0;
        levels.push(level);
        nodes.push(root);
        while (!levels.empty()) {
            vector<int> v;
            while (!levels.empty() && levels.front() == level) {
                levels.pop();
                TreeNode *node = nodes.front();
                nodes.pop();
                v.push_back(node->val);
                if (node->left != nullptr) {
                    levels.push(level + 1);
                    nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    levels.push(level + 1);
                    nodes.push(node->right);
                }
            }
            ans.push_back(v);
            level++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
