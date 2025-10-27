/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
       struct ListNode* fast=head,*slow=head;

    while(fast){//当 fast为空时，slow正好指向倒数第 K 个结点
    
        if(k>0){ //若 k 大于0 ，则 flash 先跑
            fast = fast->next;
            k--;
        }else{ //反之，则一起跑
            fast = fast->next;
            slow  = slow->next; 
        }
    }
    return slow;
}