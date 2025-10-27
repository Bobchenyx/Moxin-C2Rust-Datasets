/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = dummy;
    if (l1 == NULL && l2 == NULL) return NULL;
    while (l1 != NULL || l2 != NULL) {
        int var1 = (l1 != NULL) ? l1->val : INT_MAX;
        int var2 = (l2 != NULL) ? l2->val : INT_MAX;
        if (var1 <= var2) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    return dummy->next;
}