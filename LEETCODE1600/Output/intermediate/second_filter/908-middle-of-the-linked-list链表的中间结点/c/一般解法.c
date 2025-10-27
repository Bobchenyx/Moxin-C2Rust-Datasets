/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *a = head;
    struct ListNode *b = head;
    int count = 0;

    while(a->next != NULL)
    {
        a = a->next;
        count++;
    }
    int n = count / 2;
    if(count % 2 != 0) n++;

    for(int i = 0; i < n; i++)
    {
        b = b->next;
    }

    return b;
}