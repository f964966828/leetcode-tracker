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
    void traverse(TreeNode* node, vector<TreeNode*> &nodes) {
        if (!node) return;
        traverse(node->left, nodes);
        nodes.push_back(node);
        traverse(node->right, nodes);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<TreeNode*> nodes1, nodes2;
        traverse(root1, nodes1);
        traverse(root2, nodes2);
        
        int j = nodes2.size() - 1;
        for (int i = 0; i < nodes1.size(); i++) {
            while (j && nodes2[j]->val > target - nodes1[i]->val) j--;
            if (j && nodes2[j]->val == target - nodes1[i]->val) return true;
        }

        return false;
    }
};
