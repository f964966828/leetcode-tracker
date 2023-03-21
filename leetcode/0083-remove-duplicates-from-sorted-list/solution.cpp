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
    ListNode* deleteDuplicates(ListNode* head) {
        int prev = INT_MAX;
        vector<ListNode*> lists;
        while(head){
            if(head->val != prev){
                lists.push_back(head);
            }
            prev = head->val;
            head = head->next;
        }
        
        for(int i=0; i<lists.size(); i++){
            lists[i]->next = nullptr;
            if(i >= 1)
                lists[i-1]->next = lists[i];
        }

        return (lists.empty() ? nullptr : lists[0]);
    }
};
