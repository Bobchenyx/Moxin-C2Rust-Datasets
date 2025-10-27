/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 
 *     struct ListNode *next;
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1,*p2;
    p2=(struct ListNode*)malloc(sizeof(struct ListNode));
    p1=(struct ListNode*)malloc(sizeof(struct ListNode));
    p2=p1;
           
    while(l1!=NULL&&l2!=NULL)
    {

        if(l1->val<l2->val) 
        {
            p1->next=l1;
            l1=l1->next;
        }
        else 
        {
            p1->next=l2;
            l2=l2->next;
        }
        p1=p1->next;  
    }
    p1->next =(l1== NULL) ? l2 :l1;//此时L1和L2中的一个可以是非空的，因此将非空列表连接到合并列表的末尾。


    return p2->next;
}