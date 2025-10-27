/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *next = NULL;

    if (!head || !head->next) {
        return head;
    }
    next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;

    return next;

}