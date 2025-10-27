/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode*p=head;
    //此处用于处理头结点，例如1，1，1，2，3，head=1，处理后2，3，head=2
    while(p->next&&p->val==p->next->val)
        p=p->next;
    if(p!=head)
        head=p->next;
    if(head==NULL||head->next==NULL)
        return head;
    //
    if(head->val!=head->next->val)
        head->next=deleteDuplicates(head->next);
    else
        return deleteDuplicates(head);
    return head;
}