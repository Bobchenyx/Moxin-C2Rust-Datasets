/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* p=head;
    struct ListNode* q=head;
    int i=k;
    while(i-->0)
    p=p->next;
    while(p!=0)
    {
        p=p->next;
        q=q->next;
    }
    return q;
}