/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    if(!head) return head;
    int len = 0;
    struct ListNode* p = head;
    while(p){
        len++;
        p = p->next;
    }
    len /= 2;
    while(len){
        head = head->next;
        len--;
    }
    return head;
}