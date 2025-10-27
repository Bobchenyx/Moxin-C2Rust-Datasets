/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
   struct ListNode*pre=NULL,*cur=head;
   while(cur){
       struct ListNode*nex=cur->next;
       cur->next=pre;
       pre=cur;
       cur=nex;
   }
   return pre;
}