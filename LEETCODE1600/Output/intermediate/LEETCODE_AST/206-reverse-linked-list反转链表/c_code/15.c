/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode *head){

    struct ListNode *cur = NULL;
    struct ListNode *next = head;
    struct ListNode *tmp = NULL;
    while (next != NULL) {
        tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }
    return cur;
}