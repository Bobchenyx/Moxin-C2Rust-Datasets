struct ListNode* swapPairs(struct ListNode* head){
    if(head==0||head->next==0) return head;
    struct ListNode* odd=head, * even=odd->next;
    head=even;
    
    odd->next=even->next;
    even->next=odd;
    odd->next=swapPairs(odd->next);

    return head;
}