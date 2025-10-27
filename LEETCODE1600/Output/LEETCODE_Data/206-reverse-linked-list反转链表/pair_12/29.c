struct ListNode* __reverseList(struct ListNode* head, struct ListNode* pre){
    struct ListNode* tmp = head->next;
    head->next = pre;
    return tmp ? __reverseList(tmp, head) : head;
}

struct ListNode* reverseList(struct ListNode* head){
    return head ? __reverseList(head, NULL) : NULL;
}