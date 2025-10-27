/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head;
    int len = 0 ;
    while(p!=NULL)
    {
        p=p->next;
        len = len + 1 ;
    }
    len = len - n + 1 ;
    p=head;
    if(len==1)return head->next;
    while(len-2>0)
    {
        p=p->next;
        len--;
    }
    p->next=p->next->next;
    return head;
}