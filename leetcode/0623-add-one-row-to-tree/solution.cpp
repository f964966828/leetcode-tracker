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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        vector<TreeNode*> bfs;

        while (--depth) {
            if (bfs.empty()) {
                bfs.push_back(root);
            } else {
                vector<TreeNode*> new_bfs;
                for (auto node: bfs) {
                    if (node->left) {
                        new_bfs.push_back(node->left);
                    }
                    if (node->right) {
                        new_bfs.push_back(node->right);
                    }
                }
                bfs = new_bfs;
            }
        }

        for (auto node: bfs) {
            TreeNode* left = new TreeNode(val, node->left, nullptr);
            TreeNode* right = new TreeNode(val, nullptr, node->right);
            node->left = left;
            node->right = right;
        }

        if (bfs.empty()) { // depth == 1
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        } else {
            return root;
        }
    }
};
