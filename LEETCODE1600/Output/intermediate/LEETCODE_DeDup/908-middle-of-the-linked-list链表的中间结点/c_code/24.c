/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    /*特殊情况:只有一个节点或两个节点*/
    if(head==NULL||head->next==NULL)return head;
    if(head->next->next==NULL)return head->next; 
    //二倍速快慢指针
    struct ListNode *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}