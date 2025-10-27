/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//不加头节点
struct ListNode* Merge(struct ListNode *l1,struct ListNode *l2)
{
    if(!l1)return l2;
    if(!l2)return l1;
    struct ListNode *p1=l1,*p2=l2,*head;
    if(p1->val>p2->val)//小的做表头
    {
        p2=l1;p1=l2;
    }   
    head=p1;
    while(p1->next&&p2->next)//把p2插入到p1链表
    {
        if(p1->next->val>p2->next->val)//p2的插入条件
        {
            struct ListNode *q=p2->next;
            p2->next=q->next;
            q->next=p1->next;
            p1->next=q;
        }
        p1=p1->next;
    }
    //三种可能结束条件
    if(p2->next&&!p1->next)
        p1->next=p2->next;
    if(p2==l1)//插入到l2中
    {
        while(l2->next&&l2->next->val<=p2->val)
            l2=l2->next;
        p2->next=l2->next;
        l2->next=p2;
        return head;
    }
    //插入到l1
    while(l1->next&&l1->next->val<=p2->val)
    l1=l1->next;
    p2->next=l1->next;
    l1->next=p2;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)return NULL;
    if(listsSize==1)return lists[0];
    struct ListNode* head=Merge(lists[0],lists[1]);
    int i;
    for(i=2;i<listsSize;i++)
    head=Merge(head,lists[i]);
    return head;
}