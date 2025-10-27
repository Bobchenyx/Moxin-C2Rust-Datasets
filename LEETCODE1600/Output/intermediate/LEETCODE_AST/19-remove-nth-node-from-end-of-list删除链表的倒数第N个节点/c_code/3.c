struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* pre, *p;
    pre = head;
    p = head;
    int i=1;
    int grap = n+1;
    while(i!=grap)
    {
        p=p->next;
        i++;
    }
    if(p == NULL)
    {
         head = head->next;
         return head;
    }
    while(p->next)
    {
        pre = pre->next;
        p = p->next;
    }
    pre->next = pre->next->next;
    return head;
}