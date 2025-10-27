/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){  //栈实现递归法;
if(head==NULL || head->next==NULL)  //当为空和仅有一个值时 就直接返回;
return head;
struct ListNode *p;
p=reverseList(head->next) ;//先到尾，往下层去;
head->next->next=head;
head->next=NULL;
return p; 
}