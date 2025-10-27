/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode* ps=NULL;//指向pr前面
	struct ListNode* pr=NULL;//指向px前面
	struct ListNode* px=head;//链接指针
	struct ListNode* link=NULL;//链接指针
	int flag1=0;
    if(head==NULL)
    {
        return NULL;
    }
	if(head->next==NULL)
	{
		return head;
	}
	pr=px;
	px=px->next;
	while(px)
	{
		if(flag1==0)
		{
			ps=pr;
			pr=px;
			px=px->next;
			pr->next=ps;
			ps->next=NULL;
			head=pr;
			link=ps;
			flag1=1;
		}
		if(px&&px->next==NULL)
		{
			link->next=px;
            px=px->next;;

		}
		else if(px&&px->next)
		{
			pr=px;
			px=px->next;
			ps=pr;
			pr=px;
			px=px->next;
			pr->next=ps;
			ps->next=NULL;
			link->next=pr;
			link=ps;
		}
	}
	return head;
}