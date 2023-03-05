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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sum;
        vector<TreeNode*> tree_lists(1, root);
        while(!tree_lists.empty()){
            long long sum = 0;
            vector<TreeNode*> new_lists;
            for(auto node: tree_lists){
                if(node->left) new_lists.push_back(node->left);
                if(node->right) new_lists.push_back(node->right);
                sum += node->val;
            }
            level_sum.push_back(sum);
            tree_lists = new_lists;
        }
        sort(level_sum.begin(), level_sum.end());
        
        if(k<=level_sum.size())
            return level_sum[level_sum.size() - k];
        else
            return -1;
    }
};
