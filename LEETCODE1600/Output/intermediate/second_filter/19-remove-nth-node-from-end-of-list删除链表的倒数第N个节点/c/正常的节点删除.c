/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0;
    int step = 0;
    struct ListNode * tmp = head;
    struct ListNode * res = head;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    if (len == 1) return NULL;
    step = len - n;
    if (step == 0) res = head->next;
    for (int i = 0; i < step - 1; i++) 
        head = head->next;
    //printf("%d ", head->val);
    head->next = head->next->next;
    return res;


}