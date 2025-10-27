struct ListNode* deleteDuplicates(struct ListNode* head){
    //1.首先解决特殊情况
    if(head==NULL||head->next==NULL)
        return head;
    
    //2.构建虚拟头结点
    struct ListNode *s=(struct ListNode*)malloc(sizeof(struct ListNode));
    s->next=head;
    head=s;

    //3.构建几个指针，pre指针，curr指针，用curr指针遍历
    struct ListNode *pre=head;
    struct ListNode *curr=head->next;
    while(curr->next!=NULL&&curr!=NULL)
    {
        if(curr->next->val!=curr->val)
        {
               pre=curr;
               curr=curr->next;
        }
        else
        {
            struct ListNode *p=curr->next;
            while(p!=NULL&&p->val==curr->val)
            {
                p=p->next;
            }
            pre->next=p;
            if(p==NULL)
            {
                pre->next=NULL;
                return head->next;
            }
            curr=p;
        }
    }
   
    return head->next;

}