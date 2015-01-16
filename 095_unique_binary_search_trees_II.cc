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
    vector<TreeNode *> generateTrees(vector<int> &v, int start, int end) {
        vector<TreeNode *> ans;
        if (start == end) {
            ans.push_back(nullptr);
            return ans;
        }
        if (start == end + 1) {
            TreeNode *root = new TreeNode(v[start]);
            ans.push_back(root);
            return ans;
        }
        for (int i = start; i < end; ++i) {
            vector<TreeNode *> left_sub_trees = generateTrees(v, start, i);
            vector<TreeNode *> right_sub_trees = generateTrees(v, i + 1, end);
            int left_size = left_sub_trees.size(), right_size = right_sub_trees.size();
            for (int j = 0; j < left_size; ++j) {
                for (int k = 0; k < right_size; ++k) {
                    TreeNode *root = new TreeNode(v[i]);
                    root->left = left_sub_trees[j];
                    root->right = right_sub_trees[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<int> v;
        for (int i = 0; i < n; ++i) v.push_back(i + 1);
        return generateTrees(v, 0, n);

    }
};
