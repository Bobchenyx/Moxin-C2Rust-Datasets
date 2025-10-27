/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL) return NULL;
    struct ListNode *sentinel = (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->next=head;
    struct ListNode *prior=sentinel,*p=head;
    while(p!=NULL){
        if(p->val==val){    //双指针法
            prior->next=p->next;
            p=p->next;
        }else{
            prior=p;
            p=p->next;
        }
    }
    return sentinel->next;
}