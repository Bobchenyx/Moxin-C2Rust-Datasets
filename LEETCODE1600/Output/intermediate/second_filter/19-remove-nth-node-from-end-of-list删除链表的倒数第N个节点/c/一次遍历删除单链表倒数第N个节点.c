/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *front = head;
    struct ListNode *last = head;
    while (n>0){
        front = front->next;
        n--;
    }
    if (front == NULL){
        return last->next;
    }
    while (front->next != NULL){
        front = front->next;
        last = last->next;
    }
    last->next = last->next->next;
    return head;
}