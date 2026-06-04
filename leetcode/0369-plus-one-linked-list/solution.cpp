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
    void helper(ListNode* head) {
        if (head->next) {
            helper(head->next);
            if (head->next->val == 10) {
                head->next->val = 0;
                head->val++;
            }
        } else {
            head->val++;
        }
    }

    ListNode* plusOne(ListNode* head) {
        helper(head);
        if (head->val == 10) {
            head->val = 0;
            ListNode* node = new ListNode(1, head);
            return node;
        } else {
            return head;
        }
    }
};
