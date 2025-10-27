/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode *evenHead = NULL;
    struct ListNode *oddHead = NULL;
    struct ListNode *curEven = NULL;
    struct ListNode *curOdd = NULL;
    struct ListNode *cur = NULL;
    int inx = 0;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    evenHead = curEven = head;
    oddHead = curOdd = head->next;
    cur = head->next->next;
    inx = 2;
    while(cur != NULL) {
        if (inx % 2 == 0) {
            curEven->next = cur;
            curEven = cur;
        } else {
            curOdd->next = cur;
            curOdd = cur;
        }
        inx++;
        cur = cur->next;
    }
    curEven->next = oddHead;
    curOdd->next = NULL;
    return evenHead;
}