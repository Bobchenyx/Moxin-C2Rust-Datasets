/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getValue(struct ListNode *n){
    if(n==NULL)
    {
        return 0;
    }
    return n->val;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* p = result;
    bool greaterThan9 = false;
    
    p->val = getValue(l1) + getValue(l2);
    if(p->val>9){
        greaterThan9 = true;
        p->val -=10;
    }
    l1 = l1->next;
    l2 = l2->next;
    while(l1!=NULL || l2!=NULL){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p= p->next;
        p->val = getValue(l1) + getValue(l2);
        if(greaterThan9){
            p->val++;
            greaterThan9=false;
        }
        if(p->val>9){
            greaterThan9 = true;
            p->val -=10;
        }
        
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL){
            l2 = l2->next;
        }
    }
    if(greaterThan9){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p= p->next;
        p->val=1;
    }
    p->next = NULL;
    return result;
}