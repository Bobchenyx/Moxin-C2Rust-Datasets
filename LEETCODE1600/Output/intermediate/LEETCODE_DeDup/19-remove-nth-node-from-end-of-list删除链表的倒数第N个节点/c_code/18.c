/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* ptr = head; 
    struct ListNode* delayN = head;
    int count = 0;
    
    while(ptr->next != NULL){ // length > 1
        count < n ? count = count + 1 : (delayN = delayN->next);
        ptr = ptr->next;
    }
    (count == n) ? (delayN->next = delayN->next->next) : (head = head->next);
    return head;    
}