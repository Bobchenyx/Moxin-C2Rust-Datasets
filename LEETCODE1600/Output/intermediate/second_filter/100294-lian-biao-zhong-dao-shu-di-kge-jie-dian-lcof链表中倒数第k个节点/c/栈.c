/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int **stack,top=-1;
    struct ListNode *p;
    stack = (struct ListNode**)malloc(sizeof(struct ListNode*)*1000);
    p = head;
    while(p){
        stack[++top] = p;
        p = p->next;
    }
    return stack[top+1-k];
}