struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *pre = head, *q = pre;
	while (n--)//q先向后走n步
		q = q->next;
    if(!q)//q为NULL，要删除头结点
    {
        head = head->next;
        return head;
    }
	while (q->next != NULL)//q不是NULL，双指针同时向后走
	{
		q = q->next;
		pre = pre->next;
	}
//此时pre指向要删除结点的前驱
	pre->next = pre->next->next;
	return head;
}