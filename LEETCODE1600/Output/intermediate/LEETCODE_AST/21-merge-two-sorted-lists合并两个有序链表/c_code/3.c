/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * mergeTwoLists(struct ListNode * l1, struct ListNode * l2)
{
	if(l1 == NULL && l2 ==NULL)return 0;
	if(l1 == NULL)return l2;
	if(l2 == NULL)return l1;

	struct ListNode  *res = NULL;
	
	if(l1->val <= l2->val)
	{
		res = l1;
		l1 = l1->next;
	}
	else
	{
		res = l2;
		l2 = l2->next;
	}
	
	struct ListNode  *r = res;

	while(l1 != NULL && l2 != NULL)
	{
		if(l1->val <= l2->val)
		{
			r->next = l1;
			l1 = l1->next;
		}
		else
		{
			r->next = l2;
			l2 = l2->next;
		}
		r = r->next;
	}
	if(l1 != NULL)
	{
		r->next = l1;
	}
	if(l2 != NULL)
	{
		r->next = l2;
	}
	
	return res;
}