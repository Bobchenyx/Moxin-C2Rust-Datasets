/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
        struct ListNode *mid=head,*p=head;
        while(p->next&&p->next->next){
            mid=mid->next;
            p=p->next->next;
        }//while
        if(p->next==NULL)return mid;
        return mid->next;
}