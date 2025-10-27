typedef struct ListNode* PtrToNode;

struct ListNode* swapPairs(struct ListNode* head){
    PtrToNode B = NULL;                             
    if(head == NULL)
        return NULL;
    if(head->next != NULL){                
        B = head->next;   
        if (B->next == NULL){                                                                           
            B->next = head;
            head->next = NULL;           
        }else
        {            
            head->next = B->next;
            B->next = head; 
            head->next = swapPairs(head->next);                                       
        }
    }else
        return head;
    return B;
}