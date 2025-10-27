/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *cur = NULL;
    struct ListNode *next = head->next;
    while(head->next != NULL){
        head->next = cur;
        cur = head;
        head = next;
        next = head->next;
    }
    head->next = cur;
    return head;
}