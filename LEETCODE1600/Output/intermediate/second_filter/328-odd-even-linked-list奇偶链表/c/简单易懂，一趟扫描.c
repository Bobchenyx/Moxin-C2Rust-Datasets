/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
	if (!head || !head->next||!head->next->next)//考虑特殊输入
		return head;
	struct ListNode*eve = head->next, *p = head, *q = eve;
	while (q && q->next)
	{
		p->next = q->next;
		q->next = q->next->next;
		p = p->next;
		q = q->next;
	}
	p->next = eve;
	return head;
}