/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(!root) 
            return ans;

        vector<Node*> bfs(1, root);
        while(!bfs.empty()){
            vector<int> layer;
            for(auto node: bfs)
                layer.push_back(node->val);
            ans.push_back(layer);
            
            vector<Node*> nbfs;
            for(auto node: bfs){
                for(auto child: node->children){
                    nbfs.push_back(child);
                }
            }

            bfs = nbfs;
        }

        return ans;
    }
};
