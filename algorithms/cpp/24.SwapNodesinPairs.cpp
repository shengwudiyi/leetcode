// Source : https://leetcode-cn.com/problems/swap-nodes-in-pairs/
// Author : Lianfeng Shen
// Date   : 2019-05-16

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* next = head->next;
        
        head->next = swapPairs(head->next->next);
        next->next = head;
        
        return next;
    }
};