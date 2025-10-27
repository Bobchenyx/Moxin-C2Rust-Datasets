/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* headpointer,*pointer;
     headpointer=head;
    while(headpointer->next!=NULL||headpointer->next==NULL){
        pointer=headpointer;
        for(int i=0;i<n;i++){
            pointer=pointer->next;
        }
        if(pointer==NULL){
            headpointer=headpointer->next;
            return headpointer;
        }
        else if(pointer->next==NULL){
            headpointer->next=headpointer->next->next;
            return head;
        }
        
        else{
            headpointer=headpointer->next;
        }
    }
    return head;
}