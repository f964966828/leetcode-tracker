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

    pair<int, int> solver(TreeNode* node) { // (sum, # nodes)
        if (!node) return {0, 0};
        
        pair<int, int> l_ret = solver(node->left);
        pair<int, int> r_ret = solver(node->right);
        int sum = l_ret.first + r_ret.first + node->val;
        int num = l_ret.second + r_ret.second + 1;
        
        if (sum / num == node->val) ans++;
        return {sum, num};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solver(root);
        return ans;    
    }
};
