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
    string inorder1(TreeNode* root) {
        string str = " ";
        if(root) {
            str += inorder1(root->left);
            str += to_string(root->val) + " ";
            str += inorder1(root->right);
        }
        return str;
    }

    string inorder2(TreeNode* root) {
        string str = " ";
        if(root) {
            str += inorder2(root->right);
            str += to_string(root->val) + " ";
            str += inorder2(root->left);
        }
        return str;
    }

    bool isSymmetric(TreeNode* root) {
        return inorder1(root->left) == inorder2(root->right);
    }
};
