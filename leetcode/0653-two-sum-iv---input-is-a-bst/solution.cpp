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
    bool dfs(TreeNode* root, int target, unordered_map<int,int>& mp) {
        if(root == nullptr) return false;
        if(mp.find(target - root->val) != mp.end()) return true;
        
        mp[root->val] ++;

        return  dfs(root->left, target, mp) || dfs(root->right, target, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        unordered_map<int,int> mp;
        return dfs(root, k, mp);   
    }
};
