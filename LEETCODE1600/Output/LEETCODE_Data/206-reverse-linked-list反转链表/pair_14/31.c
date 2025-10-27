/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    } else {
        struct ListNode* p = reverseList(head->next);  //递归找到head->next为最后一项的情况
        head->next->next = head;                       //最后一项指向head
        head->next = NULL;                             //倒数第二项变为最后一项指向NULL
        return p;
    }
}