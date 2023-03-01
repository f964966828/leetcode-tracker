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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int cnt = 0;
        while(cur){
            cur = cur->next;
            cnt++;
        }

        cur = head;
        cnt /= 2;
        while(cnt--){
            cur = cur->next;
        }

        return cur;
    }
};
