/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        vector<Node*> bfs;
        bfs.push_back(root);
        while(!bfs.empty()){
            for(int i=1; i<bfs.size(); i++)
                bfs[i-1]->next = bfs[i];
                
            vector<Node*> nbfs;
            for(Node* node: bfs){
                if(node->left) 
                    nbfs.push_back(node->left);
                if(node->right) 
                    nbfs.push_back(node->right);
            }

            bfs = nbfs;
        }

        return root;
    }
};
