/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
if(head==NULL)
return NULL;
struct  ListNode *prehead , *p , *q;
p=head;
prehead=(struct ListNode *)malloc(sizeof(struct ListNode));
prehead->next=head  ;// 衔接头节点;
while(p->next!=NULL && p!=NULL)
{
      // 删除节点
      q=p->next;
      p->next=p->next->next;
      //头插法
      q->next=prehead->next;
      prehead->next=q;
}
return prehead->next;
}