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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode((l1->val+l2->val)%10);
        int carry = (l1->val + l2->val)/10;
        
        ListNode* cur = root;
        l1 = l1->next; l2 = l2->next;
        while(l1 != nullptr || l2 != nullptr){
            int n1 = (l1 == nullptr ? 0 : l1->val);
            int n2 = (l2 == nullptr ? 0 : l2->val);

            int n3 = n1 + n2 + carry;
            ListNode* next = new ListNode(n3%10);
            carry = n3/10;

            cur->next = next;
            cur = next;

            //move next
            l1 = (l1 == nullptr ? nullptr : l1->next);
            l2 = (l2 == nullptr ? nullptr : l2->next);
        }

        if(carry){
            ListNode* next = new ListNode(1);
            cur->next = next;
        }
        
        return root;
    }
};
