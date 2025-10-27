/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head, *p;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = head;
    if (l1 == NULL)
        head -> next = l2;
    else if (l2 == NULL)
        head -> next = l1;
   
    while (l1 && l2){
        if (l1 -> val < l2 -> val){
            head -> next = l1;
            head = l1;
            l1 = l1 -> next; 
        }
        else{
            head -> next = l2;
            head = l2;
            l2 = l2 -> next;
        }
    }
    head -> next = l1 ? l1 : l2;
    return p -> next;
}