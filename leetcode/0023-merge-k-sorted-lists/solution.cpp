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
typedef pair<int,int> pii;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap
        for(int i=0; i<lists.size(); i++){
            if(!lists[i]) continue;
            pq.push({lists[i]->val, i});
        }

        if(pq.empty()) return nullptr;

        int val = pq.top().first, idx = pq.top().second; pq.pop();
        ListNode* root = new ListNode(val);
        if(lists[idx]->next){
            lists[idx] = lists[idx]->next;
            pq.push({lists[idx]->val, idx});
        }
        
        ListNode* cur = root;
        while(!pq.empty()){
            val = pq.top().first, idx = pq.top().second; pq.pop();

            ListNode* node = new ListNode(val);
            cur->next = node;
            cur = node;

            if(lists[idx]->next){
                lists[idx] = lists[idx]->next;
                pq.push({lists[idx]->val, idx});
            }
        }
        
        return root;
    }
};
