struct ListNode* swapPairs(struct ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    struct ListNode* pre=head;
    struct ListNode* p=head->next;
    pre->next=swapPairs(p->next);
    p->next=pre;
    return p;
}