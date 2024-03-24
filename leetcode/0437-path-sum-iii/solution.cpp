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
    void dfs(int& ans, map<long long, int>& mp, TreeNode* node, int targetSum, long long p_sum) {
        p_sum += node->val;
        ans += mp[p_sum - targetSum];
        mp[p_sum]++;
        if (node->left != NULL) {
            dfs(ans, mp, node->left, targetSum, p_sum);
        }
        if (node->right != NULL) {
            dfs(ans, mp, node->right, targetSum, p_sum);
        }
        mp[p_sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        map<long long, int> mp;
        mp[0]++;
        if (root != NULL) {
            dfs(ans, mp, root, targetSum, 0);
        }
        return ans;
    }
};
