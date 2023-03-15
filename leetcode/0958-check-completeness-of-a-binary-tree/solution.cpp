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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        bool findNull = false;
        while(!bfs.empty()){
            vector<TreeNode*> nbfs;
            for(auto node: bfs){
                if(node->left && findNull)
                    return false;
                else if(node->left)
                    nbfs.push_back(node->left);
                else
                    findNull = true;

                if(node->right && findNull)
                    return false;
                else if(node->right)
                    nbfs.push_back(node->right);
                else
                    findNull = true;
            }
            bfs = nbfs;
        }
        return true;
    }
};
