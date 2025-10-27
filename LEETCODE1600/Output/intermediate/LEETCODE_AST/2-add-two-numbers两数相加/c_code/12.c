/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p = l1,* q = l2,*res,*t,*r;
    res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next = NULL;
    r = res;
    int temp,carry = 0;
    temp = p->val + q->val + carry;
    carry = temp/10;
    res->val = temp%10;
    p = p->next;
    q = q->next;
    while(p != NULL && q != NULL){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp = p->val + q->val + carry;
        carry = temp/10;
        t->val = temp%10;
        t->next = NULL;
        r->next = t;
        r = t;
        p = p->next;
        q = q->next;
    }
    if(p != NULL){
        r->next = p;
        while(carry == 1 && p != NULL){
        temp = p->val + carry;
        carry = temp/10;
        p->val = temp%10;
        r = p;
        p = p->next;
        }
    }
    if(p == NULL && carry == 1){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        r->next = t;
    }
    if(q != NULL){
        r->next = q;
        while(carry == 1 && q != NULL){
        temp = q->val + carry;
        carry = temp/10;
        q->val = temp%10;
        r = q;
        q = q->next;
        }
    }
    if(q == NULL && carry == 1){
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        r->next = t;
    }
    return res;
}