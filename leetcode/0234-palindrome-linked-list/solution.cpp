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
    bool isPalindrome(ListNode* head) {
        vector<int> seq;
        while (head != NULL) {
            seq.push_back(head->val);
            head = head->next;
        }
        
        bool ret = true;
        for (int i = 0; i < seq.size() / 2; i++) {
            if (seq[i] != seq[seq.size() - 1 - i]) {
                ret = false;
            }
        }
        
        return ret;
    }
};
