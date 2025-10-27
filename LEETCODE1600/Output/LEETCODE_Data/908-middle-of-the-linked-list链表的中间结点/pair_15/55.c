/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int sign=0;
    struct ListNode *p=head,*q=head;
    while(p->next!=NULL){
        if(sign==0){
            p=p->next;
            q=q->next;
            sign=1;
            continue;
        }
        if(sign==1){
            p=p->next;
            sign=0;
        }
    }
    return q;
}