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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while (cur != NULL) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int n = nodes.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            nodes[i]->next = nodes[n - 1 - i];
            //cout << i+1 << " " << n-i << endl;
            if (i + 1 < (n + 1) / 2) {
                nodes[n - 1 - i]->next = nodes[i + 1];
                //cout << n-i << " " << i+2 << endl;
            } else {
                nodes[n - 1 - i]->next = NULL;
                //cout << n-i << " null" << endl;
            }
        }
    }
};
