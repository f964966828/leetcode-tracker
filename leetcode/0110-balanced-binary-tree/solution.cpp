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
    int getHeight(TreeNode* root){
        if(!root) 
            return 0;
        else 
            return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) 
            return true;
        else
            return (abs(getHeight(root->left) - getHeight(root->right)) <= 1
                && isBalanced(root->left) && isBalanced(root->right));
    }
};
