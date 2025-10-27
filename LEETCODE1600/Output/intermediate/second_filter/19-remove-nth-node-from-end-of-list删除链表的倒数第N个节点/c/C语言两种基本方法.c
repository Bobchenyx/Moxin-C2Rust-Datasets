struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) return NULL;
    struct ListNode *curr = head;
    struct ListNode *curr1;
    struct ListNode *node_to_del;
    struct ListNode *dummy;
    int cnt = 0;
    int i = 0;
    while(curr != NULL)
    {
        cnt++;
        curr = curr->next;
    }

    node_to_del = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    curr1 = dummy;
    while ((curr1->next != NULL) && (i<cnt-n))
    {
        curr1 = curr1->next;
        i++;
    }
    node_to_del = curr1->next;
    if (node_to_del != NULL)
    {
        curr1->next = node_to_del->next;
    }
    free(node_to_del);
 

    return dummy->next;
}