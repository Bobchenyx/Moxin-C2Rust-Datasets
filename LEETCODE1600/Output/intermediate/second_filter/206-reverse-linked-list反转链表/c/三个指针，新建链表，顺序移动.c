/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre;
    struct ListNode* cur;
    struct ListNode* newHead;

    if (head == NULL) {
        return head;
    }

    newHead = head;
    cur = head->next;
    newHead->next = NULL;
    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
        pre->next = newHead;
        newHead = pre;
    }

    return newHead;
}