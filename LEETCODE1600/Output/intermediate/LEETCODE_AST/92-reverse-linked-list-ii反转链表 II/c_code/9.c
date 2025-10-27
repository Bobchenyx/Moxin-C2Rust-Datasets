/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode reverHead = {0};
    reverHead.next = head;

    struct ListNode *p = &reverHead;
    struct ListNode *q = reverHead.next;
    int index = 0;
    while (index < m - 1) {
        q = q->next;
        p = p->next;
        index++;
    }
    for (int i = 0; i < n - m; i++) {
        struct ListNode *tmp = q->next;
        q->next = q->next->next;

        tmp->next = p->next;
        p->next = tmp;
    }
    return reverHead.next;
}