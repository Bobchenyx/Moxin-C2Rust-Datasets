struct ListNode* oddEvenList(struct ListNode* head){
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;
    struct ListNode* last=head->next;//偶数
    struct ListNode* a=head;
    struct ListNode* b=last;//偶数
    struct ListNode* temp;
    
    temp=b->next;
    while (temp!=NULL){
        b->next=b->next->next;
        b=b->next;
        a->next=temp;
        a=a->next;
        if (b==NULL)
            break;
        temp=b->next;
    }
    a->next=last;
    return head;
}