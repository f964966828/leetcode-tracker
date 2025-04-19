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
    int solve(TreeNode* node, int mx) {
        int ret = 0;
        if (node->left) ret += solve(node->left, max(mx, node->val));
        if (node->right) ret += solve(node->right, max(mx, node->val));
        if (mx <= node->val) ret++;
        return ret;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};
