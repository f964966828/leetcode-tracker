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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, &postIndex);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int* postIndex) {
        if (inStart > inEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[*postIndex]);
        (*postIndex)--;
        
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }
        
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);
    
    return root;
}

};
