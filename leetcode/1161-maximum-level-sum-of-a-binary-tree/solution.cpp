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
    int maxLevelSum(TreeNode* root) {
        int max_sum = root->val, ans = 1, level = 1;
        vector<TreeNode*> bfs(1, root);
        while (!bfs.empty()) {
            vector<TreeNode*> new_bfs;
            for (TreeNode* node : bfs) {
                if (node->left) new_bfs.push_back(node->left);
                if (node->right) new_bfs.push_back(node->right);
            }
            bfs = new_bfs;
            level++;

            if (!bfs.empty()) {
                int sum = 0;
                for (TreeNode* node : bfs) sum += node->val;
                if (sum > max_sum) {
                    max_sum = sum;
                    ans = level;
                }
            }
        }
        return ans;
    }
};
