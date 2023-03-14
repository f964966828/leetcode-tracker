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
    int solve(TreeNode* root, string num){
        if(!root) return 0;

        num += (root->val+'0');
        if(!root->left && !root->right)
            return stoi(num);
        else 
            return solve(root->left, num) + solve(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        else return solve(root, "");
    }
};
