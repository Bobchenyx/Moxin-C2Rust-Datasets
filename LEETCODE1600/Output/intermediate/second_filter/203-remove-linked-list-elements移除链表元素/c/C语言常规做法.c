struct ListNode* removeElements(struct ListNode* head, int val){
    while(head!=0&&head->val==val) head=head->next;
    struct ListNode* tmp=head;
    while(tmp!=0)
        if(tmp->next!=0&&tmp->next->val==val) tmp->next=tmp->next->next;
        else tmp=tmp->next;
    return head;
}