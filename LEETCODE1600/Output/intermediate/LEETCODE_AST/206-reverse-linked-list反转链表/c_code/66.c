struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* cur, * pos=head;
    while(pos->next!=NULL){
        cur = pos->next;
        pos->next = cur->next;
        cur->next = head;
        head = cur;
    }
    return head;
}