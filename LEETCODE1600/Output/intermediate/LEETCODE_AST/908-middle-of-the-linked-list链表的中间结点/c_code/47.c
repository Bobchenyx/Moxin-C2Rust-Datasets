struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *pre, *p;
    pre = head;
    p=pre->next;
    while(p!=NULL&&p->next!=NULL)
    {
        pre = pre->next;
        p = p->next->next;
    }
    if(p!=NULL) pre = pre->next;
    return pre;
}