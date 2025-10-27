/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* p = head;
    struct ListNode* pre = NULL;
    struct ListNode* tmpHead = NULL;
    struct ListNode* tmpTail = NULL;

    for(int i = 0; i < n; i++) {
        struct ListNode* next = p->next;
        if (i == m-2) {
            pre = p;
        } 
        if (i >= m-1 && i < n) {
            if (i == m-1) {
                tmpTail = p;
            }
            p->next = tmpHead;
            tmpHead = p;
        } 
        p = next;
    }

    if(pre) {
        pre->next = tmpHead;
    } else {
        head = tmpHead;
    }
    tmpTail->next = p;

    return head;
}