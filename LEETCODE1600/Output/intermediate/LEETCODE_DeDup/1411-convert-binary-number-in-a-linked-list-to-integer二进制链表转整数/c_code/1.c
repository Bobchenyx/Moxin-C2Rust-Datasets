int getDecimalValue(struct ListNode* head){
    int res = 0;
    for ( ; head; head = head->next) 
        res = (res << 1) | head->val;
    return res;
}