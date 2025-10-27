/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head->val==val)
    {
        head=head->next;
        return head;
    }    
    for(struct ListNode* iter=head;iter->next!=0;iter=iter->next)
        if(iter->next->val==val)
            {
                iter->next=iter->next->next;
                return head;
            }
    return head;
}