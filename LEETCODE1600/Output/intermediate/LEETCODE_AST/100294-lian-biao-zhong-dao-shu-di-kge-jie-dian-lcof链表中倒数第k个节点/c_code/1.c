/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *newhead;
    int i = 0;
    if (head == NULL) {
        return head;
    }
    for (newhead = head; newhead != NULL; newhead = newhead->next) {
        i++;
    }
    newhead = head;
    for (; i > k; i--) {
        newhead = newhead->next;
    }

    return newhead;
}