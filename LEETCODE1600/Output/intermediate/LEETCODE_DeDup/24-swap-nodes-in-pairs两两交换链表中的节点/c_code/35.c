/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){

if(!head||!(head->next))  return head;//边界条件

struct ListNode*L,*p,*q;
L=(struct ListNode*)malloc(sizeof(struct ListNode));//头结点
L->next=head;
p=head;
q=L;
/***
两两交换相邻的结点，若为奇数个只交换前面偶数个
****/
while(p->next)
{
    q->next=p->next;//下面四步为结点交换顺序
    q=q->next;
    p->next=q->next;
    q->next=p; 
    if(p->next)//交换结点后再判断p下一个结点是有为空
    {
    p=p->next;
    q=q->next;
    }
    else
    break;
} 
return L->next;
}