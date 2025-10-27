/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if(!head||!head->next)
    return head;

    //自建头结点
    struct ListNode* new_head=(struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next=head;

    struct ListNode* pre,*q,*r;
    pre=head;
    while(pre->next)
    {
        q=pre->next;
        if(q->val<pre->val)//发生逆序
        {
            r=q->next;//分离q
            pre->next=r;
            struct ListNode *p=new_head;
            while(p->next->val<q->val)
            p=p->next;
            q->next=p->next;
            p->next=q;
        }
        else//容易忽略
        pre=pre->next;
    }
    return new_head->next;
}