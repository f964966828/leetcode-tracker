/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int idx = 0;
        while(head){
            if(head->val == INT_MAX) return true;
            head->val = INT_MAX;
            head = head->next;
            idx++;
        }
        return false;
    }
};
