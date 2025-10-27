/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* ret = head;
    int count = 1;
    while(head!=NULL&&head->next!=NULL){
        head = head->next;
        count++;
    }
    count = count/2+1;
    while(count-- > 1)    ret = ret->next;
    return ret;
}