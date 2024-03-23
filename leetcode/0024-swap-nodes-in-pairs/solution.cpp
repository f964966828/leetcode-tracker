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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while (cur != NULL) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        
        int n = nodes.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << 2 * i + 1 << " " << 2 * i + 4 << endl;
            cout << 2 * i + 2 << " " << 2 * i + 1 << endl;
            if (2 * i + 3 < n) {
                nodes[2 * i]->next = nodes[2 * i + 3];
            } else if (2 * i + 3 == n) {
                nodes[2 * i]->next = nodes[n - 1];
            } else {
                nodes[2 * i]->next = NULL;
            }

            if (2 * i + 1 < n) {
                nodes[2 * i + 1]->next = nodes[2 * i];
            }
        }

        if (nodes.size() >= 2) {
            return nodes[1];
        } else {
            return head;
        }
    }
};
