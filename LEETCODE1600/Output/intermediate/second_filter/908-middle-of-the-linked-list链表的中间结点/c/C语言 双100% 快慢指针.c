/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = NULL;
    struct ListNode *fast = NULL;
    if (head == NULL) {
        return head;
    }
    slow = fast = head;
    while(1) {
        if (fast->next == NULL || fast->next->next == NULL) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return fast->next == NULL ? slow : slow->next;
}