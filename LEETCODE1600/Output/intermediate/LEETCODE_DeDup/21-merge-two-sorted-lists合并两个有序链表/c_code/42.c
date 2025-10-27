/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *p3,*l3;
    p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3 = p3;

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            p3->next = l1;
            p3 = l1;
            l1 = l1->next;
        }else{
            p3->next = l2;
            p3 = l2;
            l2 = l2->next;
        }
    }
    p3->next = l1? l1 : l2;
    return l3->next;
}