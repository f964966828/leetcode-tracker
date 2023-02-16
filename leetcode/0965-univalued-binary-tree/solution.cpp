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
    bool checkValue(TreeNode* node, int val){
        if(!node) return true;
        return (node->val == val) && checkValue(node->left, val) && checkValue(node->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        return checkValue(root->left, root->val) && checkValue(root->right, root->val);
    }
};
