/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int n = 0;
    struct ListNode*p = head;
    int i;

    while(p){
        ++n;
        p = p->next;
    }

    n = n / 2;
    p = head;
    for(i=0;i<n;i++){
        p = p->next;
    }
    return p;
}