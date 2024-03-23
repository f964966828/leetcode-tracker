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

bool cmp(ListNode* a, ListNode* b) {
    return a->val < b->val;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> nodes;
        while (head != NULL) {
            nodes.push_back(head);
            head = head->next;
        }
        
        sort(nodes.begin(), nodes.end(), cmp);

        int n = nodes.size();
        for (int i = 0; i < n - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }

        if (n != 0) {
            nodes[n - 1]->next = NULL;
            return nodes[0];
        } else {
            return NULL;
        }
    }
};
