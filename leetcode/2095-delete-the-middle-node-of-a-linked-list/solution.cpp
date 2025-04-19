/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        if (nodes.size() == 1) {
            nodes[0] = nullptr;
        } else if (nodes.size() == 2) {
            nodes[0]->next = nullptr;
        } else {
            nodes[nodes.size() / 2 - 1]->next = nodes[nodes.size() / 2 + 1];
        }

        return nodes[0];
    }
};
