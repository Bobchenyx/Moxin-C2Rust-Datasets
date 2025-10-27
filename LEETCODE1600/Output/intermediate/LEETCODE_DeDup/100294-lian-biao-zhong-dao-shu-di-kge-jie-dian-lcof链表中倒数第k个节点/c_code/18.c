/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *res = head;

    int i = 1;
    while(i < k) {
        head = head->next;
        i++;
    }

    while(head->next) {
        head = head->next;
        res = res->next;
    }

    return res;
}