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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        queue<TreeNode *> node;
        queue<int> level;
        if (root) {
            node.push(root);
            level.push(0);
        }
        int current_level = 0;
        while (!node.empty()) {
            vector<int> v;
            while (level.front() == current_level) {
                TreeNode *n = node.front();
                v.push_back(n->val);
                if (n->left) {
                    node.push(n->left);
                    level.push(current_level + 1);
                }
                if (n->right) {
                    node.push(n->right);
                    level.push(current_level + 1);
                }
                node.pop();
                level.pop();
            }
            ans.push_back(v);
            current_level++;
        }
        return ans;
    }
};
