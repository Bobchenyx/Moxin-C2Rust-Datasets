/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)
        return NULL;
    struct ListNode* pre=head;
    struct ListNode* cur=head->next;
    struct ListNode* tmp=NULL;
    while(cur!=NULL)
    {
        tmp=cur->next;
        pre->next = cur->next;
        cur->next = head;
        head=cur;
        cur=tmp;
    }
    return head;
}