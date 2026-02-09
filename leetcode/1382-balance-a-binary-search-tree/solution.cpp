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
    void parse(TreeNode* node, vector<int>& nums) {
        if (node) {
            nums.push_back(node->val);
            if (node->left) parse(node->left, nums);
            if (node->right) parse(node->right, nums);
        }
    }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = build(nums, l, m - 1);
        node->right = build(nums, m + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        parse(root, nums);
        sort(nums.begin(), nums.end());

        int n = nums.size();
        return build(nums, 0, n - 1);
    }
};
