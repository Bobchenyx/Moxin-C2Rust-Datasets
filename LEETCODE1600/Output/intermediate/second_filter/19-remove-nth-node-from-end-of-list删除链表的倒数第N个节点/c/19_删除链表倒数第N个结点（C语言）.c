/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *end = head;
    struct ListNode *p = head;
    struct ListNode *pre = head;
    int i = 0;
    while (i < n)
    {
        end = end->next;
        i++;
    }
    if (!end){//若删除的为第一个元素
        head=head->next;
    }
    else
    {
        while (end)
        {
            pre = p;
            p = p->next;
            end = end->next;
        }
        pre->next = p->next;
        free(p);
    }

    return head;
}