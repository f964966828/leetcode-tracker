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
    
    vector<TreeNode*> lists;
    vector<string> strings;

    string traverse(TreeNode* root){
        if(!root) return "-";
        
        string str = to_string(root->val);
        str += " " + traverse(root->left);
        str += " " + traverse(root->right);

        lists.push_back(root);
        strings.push_back(str);
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        
        int n = lists.size();
        vector<TreeNode*> ans;
        vector<int> find(n, 0);
        for(int i=0; i<n; i++){
            if(find[i]) continue;
            for(int j=i+1; j<n; j++){
                if(strings[i] == strings[j]) find[i] = find[j] = 1;
            }
            if(find[i]) ans.push_back(lists[i]);
        }

        return ans;
    }
};
