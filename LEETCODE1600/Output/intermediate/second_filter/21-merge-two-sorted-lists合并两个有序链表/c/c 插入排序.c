struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode* flag=NULL,*step=NULL;
    if(l1->val > l2->val) {flag=l1;l1=l2;l2=flag;}
    while(l2)
    {
        for(flag=l1,step=flag;flag && l2->val > flag->val;step=flag,flag=flag->next);
        if(flag==l1){step=l2->next;l2->next=flag->next;flag->next=l2;}
        else{step->next=l2;step=l2->next;l2->next=flag;}
        l2=step;
    }
    return l1;
}