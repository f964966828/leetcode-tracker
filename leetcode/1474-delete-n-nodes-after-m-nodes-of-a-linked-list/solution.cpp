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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *cur = head, *prev = nullptr;
        int count = 0;
        while (cur) {
            int idx = count % (m + n);
            ListNode *next = cur->next;
            if (idx == 0 && prev) {
                prev->next = cur;
            } 
            if (idx == m - 1) {
                prev = cur;
                prev->next = nullptr;
            } else if (idx >= m) {
                delete cur;
            }
            cur = next;
            count++;
        }
        return head;
    }
};
