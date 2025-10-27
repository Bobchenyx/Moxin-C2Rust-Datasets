struct ListNode* reverseList(struct ListNode* head){
    if(head==0) return 0;
    struct ListNode*tmp,*header=head;
    while(head->next!=0){
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=header;
        header=tmp;
    }
    return header;
}