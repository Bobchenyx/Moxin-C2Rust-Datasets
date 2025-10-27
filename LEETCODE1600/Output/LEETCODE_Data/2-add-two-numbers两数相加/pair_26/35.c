typedef struct ListNode* Linklist;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    Linklist head=(Linklist)malloc(sizeof(struct ListNode));
    head->next=NULL;
    Linklist tail=head;//尾指针

    Linklist p1=l1;
    Linklist p2=l2;
    int carry=0;//进位符号
    int sum=0;

    while(p1&&p2)
    {
       sum=p1->val+p2->val+carry;
       if(sum>=10)//判断是否进位
       {
         sum-=10;
         carry=1;
       }
       else
         carry=0;
       p1=p1->next;
       p2=p2->next;

       tail->next=(Linklist)malloc(sizeof(struct ListNode));//尾指针创建一个新的结点以便将值插入
       tail=tail->next;//移动尾结点使其指向新链表的尾结点
       tail->val=sum;
    }  
    if(p1==NULL)//两个链表不相等时
       p1=p2;
    while(p1)
    {
    sum=p1->val+carry;
    if(sum>=10)
    {
      sum-=10;
      carry=1;
    }
    else
      carry=0;

    tail->next=(Linklist)malloc(sizeof(struct ListNode));
    tail=tail->next;
    tail->val=sum;
    p1=p1->next;
    }
    if(carry==1)//最后一个sum值是否进位，若进位还须添加一个尾指针，将1填入其中
    {
        tail->next=(Linklist)malloc(sizeof(struct ListNode));
        tail=tail->next;
        tail->val=carry;
    }
    tail->next=NULL;

return head->next;//返回新链表
}