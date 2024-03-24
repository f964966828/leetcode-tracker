/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool is_leaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, TreeNode* node, int targetSum) {
        path.push_back(node->val);
        targetSum -= node->val;
        if (is_leaf(node) && targetSum == 0) {
            ans.push_back(path);
        }
        if (node->left != NULL) {
            dfs(ans, path, node->left, targetSum);
        }
        if (node->right != NULL) {
            dfs(ans, path, node->right, targetSum);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if (root != NULL) {
            dfs(ans, path, root, targetSum);
        }
        return ans;
    }
};
