struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *p = head;
    
    while(1) {
        if (head->next == NULL) {
            return p;
        } else if (head->next->next == NULL) {
            return p->next;
        }
        
        head = head->next->next;
        p = p->next;
    }
}