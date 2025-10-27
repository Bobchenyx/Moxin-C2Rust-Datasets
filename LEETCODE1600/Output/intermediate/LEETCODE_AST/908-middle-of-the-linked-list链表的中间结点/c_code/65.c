struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p =head,*q= head;
    while(q->next){
        if(q->next->next == NULL)
           return p->next; 
        q = q->next->next;
        p = p->next;
    }
    return p;
}