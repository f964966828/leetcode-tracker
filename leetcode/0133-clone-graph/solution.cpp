/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneHelper(Node* node, vector<Node*>& node_list) {
        int val = node->val;
        if(node_list[val]){
            return node_list[val];
        }

        Node* new_node = new Node(val);
        node_list[val] = new_node;

        for(auto neighbor: node->neighbors){
            new_node->neighbors.push_back(cloneHelper(neighbor, node_list));
        }

        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        vector<Node*> node_list(105, NULL);
        return cloneHelper(node, node_list);
    }
};
