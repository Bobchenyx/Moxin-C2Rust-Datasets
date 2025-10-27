/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode *H = (struct ListNode*)malloc(sizeof(struct ListNode));//插入头结点
	H->next = head;
	H->val = 0;
	head = H;
	struct ListNode *after = head->next->next;
	struct ListNode *prescan = head;
	struct ListNode *scan = prescan->next;
	scan->next = NULL;
	while (after)
	{
		prescan = head;
		scan = prescan->next;//有序链表的工作指针每次都是从头开始扫描
		while (scan)
		{
			if (after->val <= scan->val)
			{
				struct ListNode *temp = after;
				after = after->next;
				temp->next = scan;
				prescan->next = temp;
				break;
			}
			prescan = scan;
			scan = scan->next;
		}
		if (!scan)//应当插入到有序链表尾部的时候
		{
			struct ListNode *temp = after;
			after = after->next;
			temp->next = scan;
			prescan->next = temp;
		}
	}
	after = head->next;
	free(head);//释放掉头结点
	return after;
}