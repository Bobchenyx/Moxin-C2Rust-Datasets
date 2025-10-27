/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *p1=head;//指向奇数
    struct ListNode *p2=head->next;//筛选出奇数
    struct ListNode *q;
    while(p2&&p2->next)
    {
        q=p2->next;//指向奇数
        p2->next=q->next;//修改指向为偶数
        p2=p2->next;
        q->next=p1->next;
        p1->next=q;
        p1=q;
    }
    return head;
}