struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){	
    if(!l1 && !l2) return NULL;
    if(!l1 && l2)  return l2;
    if(!l2 && l1)  return l1;
    struct ListNode *head; 
    l1->val < l2->val ? (head=l1,l1=l1->next):(head=l2,l2=l2->next);
    struct ListNode *cur=head;     
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next=l1;
            l1=l1->next;
        }else{
            cur->next=l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    if(!l1)  cur->next=l2;
    if(!l2)  cur->next=l1;
    return head;
}