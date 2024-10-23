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
    TreeNode* copy(TreeNode* node, int level, vector<int>& level_sums) {
        if (!node) return NULL;
        TreeNode* new_node = new TreeNode(
            level_sums[level],
            copy(node->left, level + 1, level_sums),
            copy(node->right, level + 1, level_sums)
        );
        
        int sum = 0;
        if (node->left) sum += node->left->val;
        if (node->right) sum += node->right->val;
        if (new_node->left) new_node->left->val -= sum;
        if (new_node->right) new_node->right->val -= sum;
        if (level == 0) new_node->val = 0;

        return new_node;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> level_sums;
        vector<TreeNode*> bfs(1, root);
        while (!bfs.empty()) {
            int level_sum = 0;
            vector<TreeNode*> new_bfs;
            for (auto node : bfs) {
                level_sum += node->val;
                if (node->left) new_bfs.push_back(node->left);
                if (node->right) new_bfs.push_back(node->right);
            }
            level_sums.push_back(level_sum);
            bfs = new_bfs;
        }

        return copy(root, 0, level_sums);
    }
};
