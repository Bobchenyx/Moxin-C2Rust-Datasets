/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* phead;
    struct ListNode* pre;
    struct ListNode* tail;
    phead=(struct ListNode*)malloc(sizeof(struct ListNode));
    phead->val=0;
    phead->next=head;
    pre=phead;
    tail=pre->next;
    while(tail)
    {
        if(tail->val==val)
        {
            tail=tail->next;
            pre->next=tail;
        }
        else 
        {
            pre=tail;
            tail=tail->next;
        }
    }
    return phead->next;
}