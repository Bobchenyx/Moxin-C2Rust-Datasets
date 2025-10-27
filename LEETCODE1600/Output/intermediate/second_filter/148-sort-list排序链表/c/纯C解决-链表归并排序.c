/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge(struct ListNode *p,struct ListNode *q)
{
    struct ListNode *headp=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *headq=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(p->val>q->val)//确保起始元素小的为第一个链表
    {
        struct ListNode *t=p;
        p=q;q=t;
    }
    headp->next=p;headq->next=q;
    struct ListNode *prep=headp,*preq=headq,*t;
    while(prep->next&&preq->next)
    {
        if(prep->next->val<preq->next->val)
        {
            prep=prep->next;
        }
        else
        {//把q中元素插入到p中
            //分离q
            t=preq->next;
            preq->next=t->next;
            t->next=prep->next;
            prep->next=t;
            prep=t;
        }
    }
    if(preq->next)
        {
            prep->next=preq->next;
        }
    p=headp;
    return headp->next;
}
struct ListNode* sortList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *p=head;
    struct ListNode *q=head->next;
    while(q&&q->next)
    {
        p=p->next;
        q=q->next->next;
    }
    q=p->next;
    p->next=NULL;
    return merge(sortList(head),sortList(q));
}