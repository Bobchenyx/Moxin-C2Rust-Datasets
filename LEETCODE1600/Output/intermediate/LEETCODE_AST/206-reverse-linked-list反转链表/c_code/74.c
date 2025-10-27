struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p=head;
    struct ListNode* q=NULL;      
    while(p!=NULL){
        p=p->next;
        head->next=q;
        q=head;
        head=p;
    }
    return q;
}