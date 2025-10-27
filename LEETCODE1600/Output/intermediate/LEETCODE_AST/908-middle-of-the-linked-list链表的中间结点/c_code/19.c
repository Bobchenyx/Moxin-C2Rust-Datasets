/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
   // printf("%d",head->val);
   struct ListNode *p[100];
   int cnt=0;
   while(head!=NULL)
   {
       p[cnt++]=head;
       head=head->next;
   }
    return p[cnt/2];
}