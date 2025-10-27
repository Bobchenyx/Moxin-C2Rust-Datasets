/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre,*cur,*pion;
    pre=NULL;
    cur=head;
    while(cur!=NULL){
        pion=cur->next;
        cur->next=pre;
        pre=cur;
        cur=pion;
    }
    return pre;

}