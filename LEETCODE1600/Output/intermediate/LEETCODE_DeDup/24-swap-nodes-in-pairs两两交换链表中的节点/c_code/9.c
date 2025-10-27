/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p,*q,*r;
    struct ListNode *new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head == NULL || head->next == NULL) return head;

    new_head->next = head;
    r = new_head;

    p = head;
    q = head->next;
    

    while(p && q){
        r->next = q;
        p->next = q->next;
        q->next = p;
        p = p->next;
        if(p == NULL) break;
        else{
            if(p->next == NULL) break;
            else{
                r = q->next;
                q = p->next;
            }
        }
    }

    return new_head->next;



}