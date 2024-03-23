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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        vector<TreeNode*> bfs(1, root);
        while (!bfs.empty()) {
            int mx = INT_MIN;
            vector<TreeNode*> new_bfs;
            for (auto node: bfs) {
                mx = max(mx, node->val);
                if (node->left != NULL) {
                    new_bfs.push_back(node->left);
                }
                if (node->right != NULL) {
                    new_bfs.push_back(node->right);
                }
            }
            bfs = new_bfs;
            ans.push_back(mx);
        }
        return ans;
    } 
};
