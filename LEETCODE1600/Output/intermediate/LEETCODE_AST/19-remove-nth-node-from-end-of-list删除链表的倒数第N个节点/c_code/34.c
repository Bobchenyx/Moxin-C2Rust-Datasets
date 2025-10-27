/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (head == NULL || n <= 0)
        return head;
    struct ListNode *p = NULL, *q = NULL;
    struct ListNode *temp = NULL;
    p = head;
    for (int i = 0; i < n; i++)
    {
        p = p ->next;
        if (p == NULL)
        {
            temp = head;
            head = head ->next;
            free(temp);
            return head;
        }
    }
    q = head;
    while (p != NULL && p ->next != NULL)
    {
        p = p ->next;
        q = q ->next;
    }
    temp = q ->next;
    q ->next = q ->next ->next;
    free(temp);
    return head;
}