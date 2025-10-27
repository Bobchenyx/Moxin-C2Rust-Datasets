/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *fast = head;
	struct ListNode *slow = head;
    while(fast!=NULL)
    {
        if(--k<0)slow=slow->next;
        fast=fast->next;
        if(slow==NULL&&k>0)return 0;
    }
    return slow;
	

}