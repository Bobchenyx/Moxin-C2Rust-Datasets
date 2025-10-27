struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = head;
    struct ListNode *p=L,*q=L;
    for(int i=0;i<n+1;i++){
        p = p->next;
    }
    while(p){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    head = L->next;
    free(L);
    return head;
}