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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == nullptr) return ans;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!(s1.empty() && s2.empty())) {
            vector<int> v1, v2;
            while (!s1.empty()) {
                TreeNode *node = s1.top();
                s1.pop();
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
                v1.push_back(node->val);
            }
            if (!v1.empty()) ans.push_back(v1);
            while (!s2.empty()) {
                TreeNode *node = s2.top();
                s2.pop();
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
                v2.push_back(node->val);
            }
            if (!v2.empty()) ans.push_back(v2);
        }
        return ans;
    }
};
