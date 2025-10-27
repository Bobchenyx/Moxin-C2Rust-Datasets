/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head=l1;
	struct ListNode* px=l1;//找插入位置
	struct ListNode* pr=NULL;//找插入位置前一个
	struct ListNode* pk=l2;//待插入的节点
	struct ListNode* ps=NULL;//待插入节点的下一个

	//三种情况1.头插2.中间插3.尾插
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
	//第一先找插入位置
	while(pk)
	{
		ps=pk;
		pk=pk->next;
        ps->next=NULL;
		//把l2中的节点取下来，进行插入l1操作
        pr=NULL;
        px=head;
		//初始化l1
		while(px)
		{
			if(px->val>ps->val)
			{
				break;
			}
			pr=px;
			px=px->next;
		}
		//找到插入位置了
		if(px)
		{
			if(px==head)//头插
			{
				ps->next=head;
				head=ps;
			}
			else 
			{
                if(pr!=NULL)//中间插入
                {
                    ps->next=px;
                    pr->next=ps;
                }
			}

		}
		else//尾插
		{
			pr->next=ps;
		}
	}
return head;
}