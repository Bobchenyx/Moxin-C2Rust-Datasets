/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while(1)
    {
        if(p->next == NULL)
        {
            break;
        }
        else if(p->next->next == NULL)
        {
            q = q -> next;
            break;
        }
        else
        {
            p = p->next ->next;
            q = q->next;
        }
    }
    return q;
}