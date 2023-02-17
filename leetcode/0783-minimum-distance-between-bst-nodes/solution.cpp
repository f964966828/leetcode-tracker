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
    void traverse(TreeNode* node, vector<int> &vec) {
        if(!node) return;
        else{
            vec.push_back(node->val);
            traverse(node->left, vec);
            traverse(node->right, vec);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        traverse(root, vec);

        sort(vec.begin(), vec.end());
        
        int min_ = 1e9;
        for(int i=1; i<vec.size(); i++) min_ = min(min_, vec[i]-vec[i-1]);

        return min_;
    }
};
