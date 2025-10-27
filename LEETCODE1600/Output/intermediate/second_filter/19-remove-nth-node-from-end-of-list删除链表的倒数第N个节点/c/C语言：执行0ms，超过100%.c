struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p, *q;
    p = q = head;
    n++;
    while (n-- && q)
        q = q -> next;
    if (n == 0)//要删除的是首结点
        return head -> next;
    while (q){
        p = p -> next;
        q = q -> next;
    }
    p -> next = p -> next -> next;
    return head;
}