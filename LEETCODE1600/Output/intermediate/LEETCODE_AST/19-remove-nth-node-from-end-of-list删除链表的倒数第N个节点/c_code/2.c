/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteNode(struct ListNode *head, int index, int *val)
{
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;
    struct ListNode *pHead = (struct ListNode *)malloc(sizeof(struct ListNode));

    pHead->next = head;
    p1 = pHead;
    p2 = pHead;

    if (head == NULL)
        return head;

    for (int i = 0; i < index; i++) {
        if (p1->next != NULL)
            p1 = p1->next;
    }
        

    while(p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    *val = p2->next->val;
    p2->next = p2->next->next;
    return pHead->next;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head;
    int val;

    p = deleteNode(head, n, &val);
    //printf("delete node is %d\n", val);
    return p;
}