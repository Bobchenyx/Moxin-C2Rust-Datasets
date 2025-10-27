struct ListNode* reverseBetween(struct ListNode* head, int m, int n){

if(!head||!(head->next)||(m==n)) return head;
struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next=head;
struct ListNode* q,*p,*pre;
q=p=dummy;
struct ListNode *L=(struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode* rear=L;
L->next=NULL;
/**
找出第m个位置的表头p以及第m-1个位置的指针pre
**/
int count=0;
while(m-count>0)
{
pre=p;
count++;
p=p->next;
}
/*
新建L链表对【M,N】中的元素进行头插
*/
while(n-count>=0)
{
q=p;
p=p->next;
count++;
q->next=L->next;
L->next=q;
if(rear->next)
{
rear=rear->next;
rear->next=NULL;
}
}
/**
第M-1个位置的指针指向新建链表的头结点，第N个位置的指针rear指向第m+1个位置，为p结点
***/
pre->next=L->next;
rear->next=p;
head=dummy->next;
free(dummy);//释放空间
return head;
}