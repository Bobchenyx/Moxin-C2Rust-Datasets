struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*slow_p=head,*p=head;
    while(n--) p=p->next;
    if(p==0) return head->next;
    p=p->next;
    while(p!=0){
        slow_p=slow_p->next;
        p=p->next;
    }
    slow_p->next=slow_p->next->next;
    return head;
}