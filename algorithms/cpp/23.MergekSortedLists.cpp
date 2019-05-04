// Source : https://leetcode-cn.com/problems/merge-k-sorted-lists/
// Author : Lianfeng Shen
// Date   : 2019-05-04

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
vector<ListNode*> heap;

void push(ListNode* node) {
    heap.push_back(node);
    
    int i = heap.size() - 1;
    while (i > 0) {
        int pi = (i - 1) / 2;
        if (heap[pi]->val > node->val) {
            heap[i] = heap[pi];
            i = pi;
        } else {
            break;
        }
    }
    heap[i] = node;
}

ListNode* pop() {
    if (heap.size() == 0) return NULL;
    ListNode* ret = heap[0];
    ListNode* node = heap[heap.size()-1]; heap.pop_back();
    
    int i = 0;
    while (i * 2 + 1 < heap.size()) {
        int l = i * 2 + 1, r = i * 2 + 2;
        if (r < heap.size() && heap[r]->val < heap[l]->val) l = r;
        
        if (heap[l]->val < node->val) {
            heap[i] = heap[l];
            i = l;
        } else {
            break;
        }
        
    }
    heap[i] = node;
    
    return ret;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (ListNode* node: lists) {
            if (node) push(node);
        }
        
        ListNode n = ListNode(0);
        ListNode* lead = &n;
        ListNode* curr = lead;
        
        while (heap.size()) {
            ListNode* node = pop(); if(node->next) push(node->next);
            curr->next = node; curr = curr->next;
        }
        return lead->next;
    }
};