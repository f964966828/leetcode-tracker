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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        vector<TreeNode*> bfs(1, root);
        while (!bfs.empty()) {
            ans.push_back(bfs[bfs.size() - 1]->val);
            vector<TreeNode*> new_bfs;
            for (auto node: bfs) {
                if (node->left != NULL) {
                    new_bfs.push_back(node->left);
                }
                if (node->right != NULL) {
                    new_bfs.push_back(node->right);
                }
            }
            bfs = new_bfs;
        }

        return ans;
    }
};
