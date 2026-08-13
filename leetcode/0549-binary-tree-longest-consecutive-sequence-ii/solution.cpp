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

    pair<int, int> helper(TreeNode* node) {
        int incr = 1, decr = 1;
        if (node->left) {
            pair<int, int> lret = helper(node->left);
            if (node->val == node->left->val + 1) incr = max(incr, lret.first + 1);
            if (node->val == node->left->val - 1) decr = max(decr, lret.second + 1);
        }
        if (node->right) {
            pair<int, int> rret = helper(node->right);
            if (node->val == node->right->val + 1) incr = max(incr, rret.first + 1);
            if (node->val == node->right->val - 1) decr = max(decr, rret.second + 1);
        }
        ans = max(ans, incr + decr - 1);
        return {incr, decr};
    }

    int longestConsecutive(TreeNode* root) {
        helper(root);
        return ans;
    }
};
