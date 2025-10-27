struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node = {-1, NULL};
    struct ListNode* head = &node;
    struct ListNode* current = head;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val) {
            current->next = l1;
            current = current->next;
            l1 = l1->next;
        } else {
            current->next = l2;
            current = current->next;
            l2 = l2->next;
        }
    }
    if(l1 != NULL) {
        current->next = l1;
    }
    if(l2 != NULL) {
        current->next = l2;
    }
    return head->next;
}