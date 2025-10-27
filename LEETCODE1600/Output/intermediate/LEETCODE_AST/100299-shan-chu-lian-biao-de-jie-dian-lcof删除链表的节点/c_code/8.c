struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode** indirect = &head; 
    //struct ListNode* temp;
    for(; *indirect; indirect = &((*indirect)->next)){
        if((*indirect)->val == val){
            //temp = *indirect;
            *indirect = (*indirect)->next;
            //free(temp);
            break;
        }
    }
    return head;
}