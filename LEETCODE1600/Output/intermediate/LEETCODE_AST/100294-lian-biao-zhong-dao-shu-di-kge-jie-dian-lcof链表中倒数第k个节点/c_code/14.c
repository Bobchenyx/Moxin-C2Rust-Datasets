/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode*p;
    p = head;
    int n = 0;
    int i;
    while(p){
        ++n;
        p = p->next;
    }

    p = head;
    for(i=0;i<n-k;i++){
        p = p->next;
    }
    return p;
}