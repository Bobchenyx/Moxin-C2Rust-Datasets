/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(n<=0)    return head;
    if(head->next==NULL&&n==1)   return NULL;
    struct ListNode*pre=head;
    struct ListNode *p=head->next;
    struct ListNode*q=head;
    int i;
    for(i=1;i<=n&&q->next!=NULL;i++)
    {
        q=q->next;
    }
    if(i==n)
    {
        head=head->next;
        free(pre);
        return head;
    }
    while(q->next!=NULL)
    {
        pre=p;
        p=p->next;
        q=q->next;
    }
    pre->next=p->next;
    free(p);
    return head;
}