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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *from = list1, *to = list1;
        for (int i = 0; i < a - 1; i++) from = from->next;
        for (int i = 0; i < b + 1; i++) to = to->next;
        
        ListNode* tail = list2;
        while (tail->next != NULL) tail = tail->next;

        from->next = list2;
        tail->next = to;

        return list1;
    }
};
