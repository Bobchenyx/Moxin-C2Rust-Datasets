struct ListNode* reverseList(struct ListNode* head){

    if(head==NULL||head->next==NULL)   
            return head;
    struct ListNode* tr=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return tr;

}