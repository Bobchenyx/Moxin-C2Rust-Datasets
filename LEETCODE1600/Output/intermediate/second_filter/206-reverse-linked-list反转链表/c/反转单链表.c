/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代法：
/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* tmp = NULL;

    while( cur != NULL ){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}*/

//递归法：
struct ListNode* reverseList(struct ListNode* head){
    if( head == NULL || head->next == NULL ){
        return head;
    }
    struct ListNode* cur = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return cur;
}