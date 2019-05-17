// Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Lianfeng Shen
// Date   : 2019-05-17

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* lead = new ListNode(0);
        ListNode* tail = lead;
        
        lead->next = head;
        
        bool dup = false;
        for (ListNode* p = lead->next; p && p->next; p = p->next) {
            dup = dup || p->val == p->next->val;
            
            if (dup) {
                tail->next = p->next;
            } else {
                tail = tail->next;
            }
            
            dup = p->val == p->next->val;
        }
        
        if (dup) tail->next = NULL;
        
        return lead->next;
    }
};