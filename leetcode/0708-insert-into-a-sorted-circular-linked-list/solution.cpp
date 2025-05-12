/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    bool valid(Node* node, int insertVal) {
        if (node->val <= insertVal && node->next->val >= insertVal) {
            return true;
        } else if (node->val > node->next->val && (node->val <= insertVal || node->next->val >= insertVal)) {
            return true;
        } else {
            return false;
        }
    }

    Node* insert(Node* head, int insertVal) {
        if (head) {
            Node *cur = head;
            while (!valid(cur, insertVal) && cur->next != head) cur = cur->next;
            Node *node = new Node(insertVal, cur->next);
            cur->next = node;
            return head;
        } else {
            Node *node = new Node(insertVal);
            node->next = node;
            return node;
        }
    }
};
