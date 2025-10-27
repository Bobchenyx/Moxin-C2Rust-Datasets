/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL) {
        return NULL;
    }

    /* 快指针先往前移动k个节点 */
    struct ListNode *temp = head;
    while (temp != NULL && k-- > 0) {
        temp = temp->next;
    }

    /* 双指针，temp到达链表尾时，prev为倒数第k个节点 */
    struct ListNode *prev = head;
    while (temp != NULL) {
        prev = prev->next;
        temp = temp->next;
    }

    return prev;
}