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
    bool checkRange(TreeNode* root, long long mx, long long mn){
        if(!root) return true;
        return (root->val < mx && root->val > mn 
            && checkRange(root->left, root->val, mn)
            && checkRange(root->right, mx, root->val)
        );
    }

    bool isValidBST(TreeNode* root) {
        return checkRange(root, (long long) INT_MAX + 1, (long long) INT_MIN - 1);
    }
};
