/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reversal(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode *prev = NULL, *curr = head, *nx = head->next;
    while (curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = nx;
        if (nx != NULL) nx = nx->next;
    }
    curr = prev;
    return curr;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (n == 0) return head;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = reversal(head);
    struct ListNode *p = dummy;
    int step = 1;
    while (step < n) {
        p = p->next;
        step++;
    }
    p->next = p->next->next;
    dummy->next = reversal(dummy->next);
    return dummy->next;
}