struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)
    return NULL;
    struct ListNode* p0;
    int len=0;
    int point=0;
    for(p0=head;p0!=NULL;p0=p0->next)
        len++;
    int *nums=calloc(len,sizeof(int));
    for(p0=head;p0!=NULL;p0=p0->next,point++)
        nums[point]=p0->val;
    point--;
    for(p0=head;p0!=NULL;p0=p0->next,point--)
        p0->val=nums[point];
    return head;
    
}