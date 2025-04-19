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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = nullptr, *odd_node = nullptr, *even_head = nullptr, *even_node = nullptr;
        int counter = 1;
        while (head) {
            ListNode* next = head->next;
            head->next = nullptr;
            if (counter % 2) {
                if (!odd_head) {
                    odd_head = odd_node = head;
                } else {
                    odd_node->next = head;
                    odd_node = head;
                }
            } else {
                if (!even_head) {
                    even_head = even_node = head;
                } else {
                    even_node->next = head;
                    even_node = head;
                }
            }
            counter++;
            head = next;
        }

        if (odd_node) odd_node->next = even_head;
        head = odd_head;
        
        return head;
    }
};
