struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p,*L,*q;

    if(!head||!(head->next))  return head;
    L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=NULL;//新建一个链表头结点指向原链表head,
    p=L;
    q=head->next;

while(q)
{
    if(q->val==head->val)//判断是否相等
    {
        
        while(q->val==head->val)
        {
            q=q->next;//若结点数据域相等，继续遍历
            if(!q)//判断是否到链表的末尾
            break;//跳出循环
        }
        if(q!=NULL)//不为表尾，将q的位置赋给head，q继续遍历
       {
        head=q;
        q=q->next;
       }
       else//为表尾，说明元素全都是重复的结点，令其为NULL，跳出循环
       {
        head=q=NULL;
       }    
    }
    else//找到不为重复元素的结点
    {
        p->next=head;//指向这个结点
        p=p->next;//前移
        head=head->next;//前移
        if(!head)
         break;
        q=q->next;//前移

    }

}
if(head)//特殊情况时，当head有值，p为null时
    p->next=head;
else
   p->next=NULL;
    return L->next;
}