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
        vector<long long> level_sums;
        vector<TreeNode*> bfs(1, root);
        while (!bfs.empty()) {
            vector<TreeNode*> new_bfs;
            long long level_sum = 0;
            for (auto node : bfs) {
                if (node->left) new_bfs.push_back(node->left);
                if (node->right) new_bfs.push_back(node->right);
                level_sum += node->val;
            }
            level_sums.push_back(level_sum);
            bfs = new_bfs;
        }

        sort(level_sums.begin(), level_sums.end());

        if (level_sums.size() < k) {
            return -1;
        }
        return level_sums[level_sums.size() - k];
    }
};
