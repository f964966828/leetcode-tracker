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
using pii = pair<int, int>;

class Solution {
public:
    void solve(TreeNode* root, int left_count, int right_count, int& ans) {
        if (!root) return;
        ans = max(ans, max(left_count, right_count));
        solve(root->left, right_count + 1, 0, ans);
        solve(root->right, 0, left_count + 1, ans);
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root, 0, 0, ans);
        return ans;
    }
};
