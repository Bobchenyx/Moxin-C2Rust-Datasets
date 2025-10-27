/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* cur, *tmp, *del;
    int i;

    cur = head;
    tmp = head;
    del = head;

    if (n == 0) {
        return head;
    }
    for (i = 1; i < n; i++) {
        tmp = tmp->next;
    }

    while (tmp != NULL) {
        //printf("%d,%d,%d\n", cur->val, del->val, tmp->val);
        if (tmp->next == NULL) {
            if (cur == head && del == head) {
                head = cur->next;
            } else {
                cur->next = del->next;
                //free(del);
            }
            break;
        } else {
            cur = del;
            del = del->next;
            tmp = tmp->next;
        }
    }

    return head;
}