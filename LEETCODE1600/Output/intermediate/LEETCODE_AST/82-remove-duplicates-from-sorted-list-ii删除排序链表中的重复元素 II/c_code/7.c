/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *H=(struct ListNode*)malloc(sizeof(struct ListNode));//自建头节点
    H->next=NULL;
    struct ListNode *r=H;
    struct ListNode *p=head,*q=head->next;
    while(p||q)
    {
        if(q&&p->val==q->val)
        {
            while(q&&p->val==q->val)
            q=q->next;
            if(!q)
                break;
            p=q;
            q=q->next;
        }
        if(!q||p->val!=q->val)
        {
            r->next=p;
            r=r->next;
            p=p->next;
            if(q)
            q=q->next;
        }   
    }
    r->next=NULL;
    return H->next;
}