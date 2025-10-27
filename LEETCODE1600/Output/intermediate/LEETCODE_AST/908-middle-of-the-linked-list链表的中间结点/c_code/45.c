struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *p = head;
	struct ListNode *q = head;
	while(q != NULL && q->next != NULL){
        p = p->next;     
		q = q->next->next;  
	}
	return p;
}