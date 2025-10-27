/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* TheN(struct ListNode* P,int N){
    for(int i=0;i<N;i++){
        P = P->next;
    }
    return P;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* P = dummy;
    // if(TheN(P,n) == NULL){
    //     free()
    // }
    // else{
        while(TheN(P,n)->next != NULL){
            P = P->next;
        }
        struct ListNode* s = P->next;
        P->next = s->next;
        free(s);
    // }
    return dummy->next;
}