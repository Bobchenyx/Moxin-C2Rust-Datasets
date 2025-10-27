/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *p=head,*q=head;
    struct ListNode *t1,*t2,*r;
    t1=(struct ListNode*)malloc(sizeof(struct ListNode));
    t1->next=head;//自建头结点，也是头结点
    int i=1;
    while(i<m)//定位到开始改变的首节点
    {
        t1=t1->next;
        i++;
        p=p->next;
    }
    q=p;
    while(i<n)//结束的尾节点
    {
        i++;
        q=q->next;
    }
    while(p!=q)
    {
        r=p->next;
        p->next=q->next;
        q->next=p;
        p=r;

    }
    t1->next=q;
    if(m==1)
    head=t1->next;
    return head;
}