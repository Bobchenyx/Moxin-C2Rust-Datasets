struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow_p=head,*fast_p=head;
    while(fast_p!=0&&fast_p->next!=0){
        fast_p=fast_p->next->next;
        slow_p=slow_p->next;
    }
    return slow_p;
}