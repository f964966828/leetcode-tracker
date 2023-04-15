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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<vector<TreeNode*>> treeLayerList;
        vector<TreeNode*> treeLayer(1, root);
        
        while(!treeLayer.empty()){
            vector<TreeNode*> newLayer;
            for(auto node: treeLayer){
                if(!node) continue;
                newLayer.push_back(node->left);
                newLayer.push_back(node->right);
            }
            treeLayerList.push_back(treeLayer);
            treeLayer = newLayer;
        }
        
        for(auto layer: treeLayerList){
            if(layer.size() == 1){
                layer[0]->val = 0;
                continue;
            }
            
            int sum = 0;
            vector<int> valueList;
            for(auto node: layer){
                if(node){
                    valueList.push_back(node->val);
                    sum += node->val;
                }else{
                    valueList.push_back(0);
                }
            }
            
            for(int i=0; i<valueList.size(); i+=2){
                valueList[i] = valueList[i+1] = valueList[i] + valueList[i+1];
            }
            
            for(int i=0; i<layer.size(); i++){
                if(layer[i]){
                    layer[i]->val = sum - valueList[i];
                }
            }
        }
        
        return root;
    }
};
