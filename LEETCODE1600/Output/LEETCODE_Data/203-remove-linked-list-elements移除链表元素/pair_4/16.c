/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
   if(head==NULL)  return head;
   while(head!=NULL){
       if(head->val==val)
       head=head->next;
       else break;
   }
   if(head==NULL) return head;
   struct ListNode *pre=head,*cur=head->next;
   while(cur!=NULL){
    if(cur->val!=val){
         pre=cur;
         cur=cur->next;
    }
    else{
        cur=cur->next;
        pre->next=cur;
    } 
   }
return head;
}