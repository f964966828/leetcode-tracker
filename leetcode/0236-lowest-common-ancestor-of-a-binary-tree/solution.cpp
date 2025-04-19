/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find_path(TreeNode* node, TreeNode* target, vector<TreeNode*>& path) {
        path.push_back(node);
        if (node->left) find_path(node->left, target, path);
        if (node->right) find_path(node->right, target, path);

        if (path[path.size() - 1] != target) path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        find_path(root, p, path_p);
        find_path(root, q, path_q);

        reverse(path_p.begin(), path_p.end());
        for (TreeNode* node_p : path_p) {
            for (TreeNode* node_q : path_q) {
                if (node_p == node_q) return node_p;
            }
        }

        return nullptr;
    }
};
