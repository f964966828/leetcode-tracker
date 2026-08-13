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

    bool is_unival(TreeNode* node) {
        bool flag = true;
        if (node->left && !(is_unival(node->left) && node->val == node->left->val)) flag = false;
        if (node->right && !(is_unival(node->right) && node->val == node->right->val)) flag = false;
        if (flag) ans++;
        return flag;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if (root) is_unival(root);
        return ans;
    }
};
