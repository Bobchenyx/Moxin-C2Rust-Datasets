/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//l1,l2为有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p=l1;
    struct ListNode *q=l2;
    struct ListNode *l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    struct ListNode *r=l3;
    while(p!=NULL&&q!=NULL){
        if(p->val<=q->val){
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else{
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;//若两链表都到达末尾，则把最后结点指针域指空
    if(p!=NULL){
        r->next=p;
    }
    if(q!=NULL){
        r->next=q;
    }
    return l3->next;
}