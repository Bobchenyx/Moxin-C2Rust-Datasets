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

    struct ListNode *pre = &reverHead;
    struct ListNode *cur = reverHead.next;
    int index = 0;
    while (index < m - 1) {
        cur = cur->next;
        pre = pre->next;
        index++;
    }
    for (int i = 0; i < n - m; i++) {
        struct ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        tmp->next = pre->next;
        pre->next = tmp;   
    }
    return reverHead.next;
}