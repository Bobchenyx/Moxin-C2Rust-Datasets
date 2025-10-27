/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==0)return 0;
    struct ListNode* n=head;
    while(n->next!=0)
        if(n->next->val==val)
        {
            struct ListNode* del=n->next;
            n->next=del->next;
            free(del);
        }
        else
            n=n->next;
//从这
    if(head->val==val)
    {
        n=head;
        head=head->next;
        free(n);
    }
//到这，如果链表有头结点，是可以省略的
    return head;
}