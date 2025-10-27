/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        struct ListNode node;
        node.next=head;
        
        struct ListNode * pnode=&node;
        struct ListNode * pslow=head;
        struct ListNode * pfast=head;
        
        for (int i=0;i<n;i++){
            pfast=pfast->next;
        }
        while(pfast!=NULL){
            pfast=pfast->next;
            pslow=pslow->next;
            pnode=pnode->next;
            
        }
        if(pslow==head){
            head=pslow->next;
        }
        else{
            pnode->next=pslow->next;

        }
        
        return head;
}