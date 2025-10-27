/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p = head;
    struct ListNode* next = NULL;
    struct ListNode* pre = NULL;

    while(p) {
        bool repeated = false;
        next = p->next;
        while(next) {
            if(p->val == next->val) {
                next = next->next;
                repeated = true;
            } else {
                break;
            }
        }
        if (repeated) {
            if(pre) {
                pre->next = next;
            } else {
                head = next;
            }
        } else {
            pre = p;
        }
        p = next;
    }
    return head;
}