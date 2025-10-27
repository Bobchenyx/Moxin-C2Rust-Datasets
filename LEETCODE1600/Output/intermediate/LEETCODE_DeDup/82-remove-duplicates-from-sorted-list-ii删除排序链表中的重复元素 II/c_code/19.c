struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    } 

    if (head->val != head->next->val) {  // 头结点和下一个节点不同，直接递归处理下一个节点开头的链表。
        head->next = deleteDuplicates(head->next);
        return head;
    }

    struct ListNode *node = head->next;
    int val = head->val;

    while (node != NULL) {  // 相同时，遍历找到首个非相同值节点，再递归处理之。
        if (node->val != val) {
            break;
        } 
        node = node->next;
    }

    return deleteDuplicates(node);
}