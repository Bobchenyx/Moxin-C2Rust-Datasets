/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    int size=0;struct ListNode* p=head;
    while(p!=NULL){
        size++;
        p=p->next;
    }
    struct ListNode*stack[size];
    int top=-1;p=head;
    while(p!=NULL){
        stack[++top]=p;
        p=p->next;
    }
    struct ListNode* head2=stack[top];
    p=head2;
    while(top!=-1){
        p->next=stack[top--];
        p=p->next;
    }
    p->next=NULL;
    return head2;
}