int getDecimalValue(struct ListNode* head){
    int value = 0;
    struct ListNode * ptr = head;

    while (ptr)
    {
        value = (value << 1) | (ptr->val);
        ptr = ptr->next;
    }
    
    return value;
}