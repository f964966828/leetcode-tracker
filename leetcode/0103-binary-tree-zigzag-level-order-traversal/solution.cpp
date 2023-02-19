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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> lists;

        if(root) lists.push_back(root);
        while(!lists.empty()){
            vector<int> vec;
            vector<TreeNode*> new_lists;
            for(auto node: lists){
                vec.push_back(node->val);
                if(node->left) new_lists.push_back(node->left);
                if(node->right) new_lists.push_back(node->right);
            }
            ans.push_back(vec);
            lists = new_lists;
        }
        
        for(int i=0; i<ans.size(); i++){
            if(i%2) reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
