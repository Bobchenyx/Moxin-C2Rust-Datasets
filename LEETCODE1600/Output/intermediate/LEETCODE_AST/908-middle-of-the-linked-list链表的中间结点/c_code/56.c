/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* f=head;
    struct ListNode* s=head;
    while(f&&f->next){
        s=s->next;
        f=f->next->next;
    }
    return s;
}