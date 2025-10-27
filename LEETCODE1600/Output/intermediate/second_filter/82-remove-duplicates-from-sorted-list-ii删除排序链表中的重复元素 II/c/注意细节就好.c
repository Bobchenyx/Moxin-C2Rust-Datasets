/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !head->next) return head;
    struct ListNode* l=(struct ListNode*)malloc(sizeof(struct ListNode));
    l->next=head;  //空的头结点
    struct ListNode *p=l, *r=l->next;
    while (r) {
        if (r->next && r->val==r->next->val) {
            while ( r->next && r->val==r->next->val) r=r->next;
            if (r) r=r->next;
        }
        else {
            p->next=r;
            p=r;
            r=r->next;
        }
    }
    p->next=r;
    p=l;
    l=l->next;
    free(p);
    return l;
}