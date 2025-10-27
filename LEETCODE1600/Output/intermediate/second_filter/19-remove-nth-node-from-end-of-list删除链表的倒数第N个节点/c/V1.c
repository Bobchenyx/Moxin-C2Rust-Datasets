/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p,*q;
    p=q=head;
    for(int i=0;i<n;i++)
        q=q->next;
    if(q==NULL) return head->next;
    q=q->next;
    while(q!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=p->next->next;
    return head;
}