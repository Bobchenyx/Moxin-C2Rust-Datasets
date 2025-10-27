c []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    
    while(cur != NULL) {
        struct ListNode* tmp = cur;
        cur = tmp -> next;
        tmp -> next = pre;
        pre = tmp;
    };

    head -> next = NULL;
    head = pre;

    return head;
}