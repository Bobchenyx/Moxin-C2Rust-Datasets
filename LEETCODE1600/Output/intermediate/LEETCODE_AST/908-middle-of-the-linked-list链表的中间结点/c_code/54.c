/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    if(!head) return false;
    struct ListNode *p,*q;
    p=head;
    int i=0,n;
    while(p){
        p=p->next;
        ++i;
    }
    p=head;
    for(n=1;n<=i/2;++n){
            q=p;
            p=p->next;
            free(q);
        }
    return p;
}