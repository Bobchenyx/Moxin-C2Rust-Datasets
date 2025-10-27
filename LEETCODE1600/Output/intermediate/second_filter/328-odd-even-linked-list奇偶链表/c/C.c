/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int count = 1;
    struct ListNode* odd = head;
    struct ListNode* tmp = head;
    struct ListNode* Even = head->next;
    struct ListNode* evenTmp = head->next;
    while (Even != NULL && Even->next != NULL) {
        odd->next = Even->next;
        odd = Even->next;
        Even->next = odd->next;
        Even = odd->next;
    }
    odd->next = evenTmp;
    return tmp;

}