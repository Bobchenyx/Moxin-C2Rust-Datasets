/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int nodenumber = 0;
    int middlenmb = 0;
    int index = 0;
    struct ListNode* ptr;
    ptr = head;
    printf("head->val = %d\n",head->val);
    if(head == NULL) {
        printf("list is empty\n");
    }

    while(head != NULL) {
        head = head->next;
        nodenumber += 1;
    }

    if(nodenumber%2 == 0) {
        middlenmb = nodenumber/2 + 1;
    } else {
        middlenmb = (nodenumber + 1)/2;
    }
    printf("middlenmb = %d\n",middlenmb);

    printf("nodenumber = %d\n",nodenumber);

    for(index = 0; index < (middlenmb - 1); index++) {
        ptr = ptr->next;
    }
    return ptr;
}