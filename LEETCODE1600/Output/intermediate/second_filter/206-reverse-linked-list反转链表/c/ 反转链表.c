/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head) return head;
    struct ListNode* pre=NULL;
    struct ListNode* cur=head;
    struct ListNode* next=NULL;
    while(cur){
        next = cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}