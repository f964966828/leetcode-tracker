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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> lists;
        if(root) lists.push_back(root);

        while(lists.size()){
            vector<int> seq;
            vector<TreeNode*> next_lists;
            for(auto node: lists){
                seq.push_back(node->val);
                if(node->left) next_lists.push_back(node->left);
                if(node->right) next_lists.push_back(node->right);
            }
            lists = next_lists;
            ans.push_back(seq);
        }

        return ans;
    }
};
