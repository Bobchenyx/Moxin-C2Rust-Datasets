struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode node;
    node.next = head;
    struct ListNode* p = &(node);
    struct ListNode* q = head->next;
    printf("%d %d\n", p->next->val, q->val);
    while(1) {
        struct ListNode* add_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        add_node->val = p->next->val;
        add_node->next = q->next;
        q->next = add_node;
        p->next = q;
        p = add_node;
        if(p->next == NULL) break;
        if(p->next->next == NULL) break;
        q = p->next->next;
    }
    return node.next;
}