/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL || m > n)
        return false;
    int stack[10240];
    int top = -1;
    struct ListNode* p = head;
    struct ListNode* q;

    for(int i = 0; i < m-1; i++){
        p = p->next;
    }
 
    q = p;
    for(int i = 0; i < n-m+1;i++){
        stack[++top] = p->val;
        p = p->next;
    }
    while(top != -1){
        q->val = stack[top--];
        q = q->next;
    }
    return head;
}