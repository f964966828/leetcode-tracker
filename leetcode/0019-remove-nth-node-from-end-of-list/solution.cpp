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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> lists;
        while(head){
            lists.push_back(head);
            head = head->next;
        }

        int t = lists.size();
        if(t == 1) 
            return nullptr;
        else if(t == n)
            return lists[1];
        else if(n == 1)
            lists[t-n-1]->next = nullptr;
        else
            lists[t-n-1]->next = lists[t-n+1];
        
        return lists[0];
    }
};
