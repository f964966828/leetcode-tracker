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
    unordered_map<int, int> height_mp;
    unordered_map<int, int> answer_mp;

    int height(TreeNode* node) {
        if (!node) return 0;
        else if (!height_mp[node->val]) {
            height_mp[node->val] = max(height(node->left), height(node->right)) + 1;
        }
        return height_mp[node->val];
    }

    void answer(TreeNode* node, int level, int max_level) {
        if (!node) return;
        answer_mp[node->val] = max_level;
        answer(node->left, level + 1, max(max_level, level + height(node->right)));
        answer(node->right, level + 1, max(max_level, level + height(node->left)));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        answer(root, 0, 0);

        vector<int> ans;
        for (int q : queries) ans.push_back(answer_mp[q]);
        return ans;
    }
};
