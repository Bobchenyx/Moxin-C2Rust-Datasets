/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p,*pre,*q;
    pre=head;
    if(!pre){
        return head;
    }
    p=pre->next;
    if((!p)){
        return head;
    }
    int x=0;
    while(pre&&p){
        x++;
        
       
        if(x==1){
            
            pre->next=p->next;
            p->next=pre;
            head=p;
            q=pre;
        }
        else{
        
        pre->next=p->next;
        p->next=pre;
        q->next=p;
        q=pre;
        
        }
        pre=pre->next;
        if(pre){
             p=pre->next;
        }
       

    }
    return head;

}