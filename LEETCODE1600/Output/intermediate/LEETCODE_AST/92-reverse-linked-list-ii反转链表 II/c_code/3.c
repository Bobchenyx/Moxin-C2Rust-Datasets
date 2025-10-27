/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL || head->next == NULL || (m == 1 && n == 1) || m == n) {
        return head;
    }
    struct ListNode temp, *p1, *p3, *p4;
    int num = 1;
    temp.next = head;
    head = &temp;
    p1 = head;
    p3 = NULL; printf("%d,%d",m,n);
    while(p1 != NULL) {
        struct ListNode *p2 = p1->next;
        if(num == m && p2 != NULL) {
            p3 = p2;
            p1->next = p2->next;
            p2->next = NULL;
            p4 = p3;
        } else if(num > m && num < n && p2 != NULL) {
            p1->next = p2->next;
            p2->next = p3;
            p3 = p2;
        } else if(num == n) {
            p4->next = p2->next;
            p2->next = p3;
            break;
        } else {
            p1 = p1->next;
        }
        num++;
    }
    return temp.next;
}