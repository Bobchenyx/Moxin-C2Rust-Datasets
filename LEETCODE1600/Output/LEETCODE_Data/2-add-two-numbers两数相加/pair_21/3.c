/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){ 
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head -> val = 0;
    head -> next = NULL;
    struct ListNode* cur = head;
    int carry = 0;
    int x = 0,y = 0 ;
    while(l1!=NULL || l2!= NULL)    
    {
        if (l1 == NULL) 
            x = 0;    
        else x = l1->val;
        if (l2 == NULL)
            y = 0;
        else y = l2->val;
        struct ListNode* p = (struct ListNode*) malloc(sizeof(struct ListNode));
        p->next = NULL;
        p -> val = (x+y+carry) % 10;
        carry = (x+y+carry) / 10;
        cur -> next = p;
        cur = cur -> next;       
        if(l1 != NULL)      
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    if(carry == 1)
    {
        struct ListNode* ca = (struct ListNode*) malloc(sizeof(struct ListNode));
        ca -> val = 1;
        ca -> next = NULL;
        cur -> next = ca;
    }
    return head->next;
}