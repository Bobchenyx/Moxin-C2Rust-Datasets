/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (slow && fast) {
        slow = slow->next;
        fast = (fast->next) ? fast->next->next : NULL;
    }
    return slow;
}