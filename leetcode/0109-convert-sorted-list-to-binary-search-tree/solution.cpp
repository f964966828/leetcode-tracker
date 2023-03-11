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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* constructBST(vector<ListNode*> lists, int s, int e){
        TreeNode* node = new TreeNode;
        if(s == e){
            node->val = lists[s]->val;
        }else{
            int m = (s+e)/2;
            node->val = lists[m]->val;
            if(s <= m-1) node->left = constructBST(lists, s, m-1);
            if(e >= m+1) node->right = constructBST(lists, m+1, e);
        }

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) 
            return nullptr;

        vector<ListNode*> lists;
        while(head){
            lists.push_back(head);
            head = head->next;
        }

        int n = lists.size();
        return constructBST(lists, 0, n-1);
    }
};
