struct ListNode* middleNode(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* fir = head;
    struct ListNode* sec = head->next->next;
    while (sec != NULL) {
        sec = sec->next;
        if (sec == NULL) return fir->next;
        sec = sec->next;
        fir = fir->next;
    }
    return fir->next;
}