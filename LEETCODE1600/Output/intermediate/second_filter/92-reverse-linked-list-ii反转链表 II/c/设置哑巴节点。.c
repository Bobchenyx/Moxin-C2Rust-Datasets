/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) {
        return NULL;
    }

    int cnt = 0;
    struct ListNode *preHead = calloc(1, sizeof(struct ListNode));
    preHead->next = head;
    struct ListNode *first = preHead;
    head = preHead;

    while (cnt < m - 1) {
        cnt++;
        head = head->next;
    }
    first = head;

    struct ListNode *second = first->next;
    struct ListNode *tmp = NULL;
    struct ListNode *p = NULL;

    while (cnt <= n) {
        p = head->next;
        head->next = tmp;
        tmp = head;
        head = p;

        cnt++;
    }

    first->next = tmp;
    second->next = p;

    return preHead->next;
}