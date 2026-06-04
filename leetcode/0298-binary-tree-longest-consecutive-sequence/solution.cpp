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
    int ans = 0;

    void helper(TreeNode* node, int depth) {
        ans = max(ans, depth);
        if (node->left) helper(node->left, node->val + 1 == node->left->val ? depth + 1 : 1);
        if (node->right) helper(node->right, node->val + 1 == node->right->val ? depth + 1 : 1);
    }

    int longestConsecutive(TreeNode* root) {
        helper(root, 1);
        return ans;
    }
};
