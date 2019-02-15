// Source:  https://leetcode-cn.com/problems/two-sum/
// Author:  Lianfeng Shen
// Date:    2019-02-15

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL, **p=&head;
        int carry=0, sum;
        
        while(l1 != NULL || l2 != NULL || carry != 0){
            sum = getValueAndMoveNext(l1) + getValueAndMoveNext(l2) + carry;
            carry = sum / 10;
            
            ListNode *node = new ListNode(sum % 10);
            *p = node;
            p = &(node->next);
        }
        return head;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int val = 0;
        if(l != NULL){
            val = l->val;
            l   = l->next;
        }
        return val;
    }
};
