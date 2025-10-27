/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){    
    //    # p1=l1
        // # p2=l2
        struct ListNode* p=NULL;
        struct ListNode* h=NULL;
        struct ListNode* t;
        // # t=None
        int c=0;
        while(!(l1==NULL&&l2==NULL&&c==0)){
            c=((l1==NULL)?0:l1->val)+((l2==NULL)?0:l2->val)+c;
            if(p==NULL){
                p=(struct ListNode*)calloc(1,sizeof(struct ListNode));
                p->val= c%10;
                h=p;        
                // # p.next=t    
            }
            else{
                t=(struct ListNode*)calloc(1,sizeof(struct ListNode));   
                t->val= c%10;     
                p->next=t;
                p=p->next;
            }
            // if(h==NULL){
            //     h=p;
            //     }            
            c/=10;
            l1=(l1==NULL)?NULL:l1->next;
            l2=(l2==NULL)?NULL:l2->next;
        }
        return h;


}