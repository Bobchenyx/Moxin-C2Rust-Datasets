struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode header;
    header.next=head;
    struct ListNode *end=head;
    head=&header;
    while(head->next){
        while(end&&end->val==head->next->val) end=end->next;
        if(end!=head->next->next) head->next=end;
        else head=head->next;
    }
    return header.next;
}