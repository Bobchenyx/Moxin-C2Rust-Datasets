/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p,*q,*pre;
    int len=0;
    pre=head;
    p=head;
    q=head;
    while(n--){
        q=q->next;
        if(!q&&n==1){
            return NULL;
        }

    }
    if(q==NULL){
        head=p->next;
    }
    
    while(q){
        pre=p;
        p=p->next;
        q=q->next;
    }
    pre->next=p->next;
    return head;
}