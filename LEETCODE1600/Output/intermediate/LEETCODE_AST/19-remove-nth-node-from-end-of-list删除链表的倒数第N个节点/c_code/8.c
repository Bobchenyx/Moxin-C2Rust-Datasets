/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* a;//后指针
    struct ListNode* b;//前指针
    a=head;//a指向头指针
    b=head;
    for(int i=0;i<n;i++)
    {
        if(b->next)
            b=b->next;//若b->next不为空则将指针向后推
        else
            return head->next;
    }
    while(b->next)
    {
        a=a->next;
        b=b->next;
    }
    a->next=a->next->next;
    return head;
}