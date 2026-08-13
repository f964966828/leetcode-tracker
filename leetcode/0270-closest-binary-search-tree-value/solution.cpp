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
    int closestValue(TreeNode* root, double target) {
        double mn = INT_MAX;
        int ans = -1;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();
            
            double dist = abs(target - node->val);
            if (dist < mn) {
                mn = dist;
                ans = node->val;
            } else if (dist == mn) {
                ans = min(ans, node->val);
            }

            if (node->left) bfs.push(node->left);
            if (node->right) bfs.push(node->right);
        }
        return ans;
    }
};
