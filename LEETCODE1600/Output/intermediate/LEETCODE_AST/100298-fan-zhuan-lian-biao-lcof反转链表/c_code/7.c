/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    //双指针法
    if(head==NULL||head->next==NULL)return head;
    struct ListNode *p=NULL,*q=head,*temp=NULL;
    while(q!=NULL){
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    return p;
}