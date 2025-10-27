/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* p = head;
    struct ListNode* q;

    if(head->val==val){
        head = head->next;
        return head;
    }
    while(p->next->val!=val){
        p = p->next;
    }

    q = p->next;

    p->next = q->next;
    return head;
}