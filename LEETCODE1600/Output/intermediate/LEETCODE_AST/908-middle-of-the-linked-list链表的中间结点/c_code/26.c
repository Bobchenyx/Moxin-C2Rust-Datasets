/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* x1=head,*x2=head;
    while(x2!=0&&x2->next!=0)
    {
        x1=x1->next;
        x2=x2->next->next;
    }
    return x1;
}