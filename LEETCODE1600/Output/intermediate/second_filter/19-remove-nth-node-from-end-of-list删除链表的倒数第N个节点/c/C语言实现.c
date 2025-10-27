/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    int count = 1;
    // if(!p->next){
    //     head = head->next;
    //     return head;
    // }
    while(p->next){
        p = p->next;
        if(count++ > n){
            q = q->next;
        }
    }
    if(count == n){
        return head = head->next;
    }
    else{
        q->next = q->next->next;
        return head;
    }
    

}