/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int cnt=0;
    struct ListNode *p=head,*q=head;
    while(q)
    {
        if(cnt>=k)
        {
            p=p->next;
        }
        q=q->next;
        cnt++;
    }
    return p;
}