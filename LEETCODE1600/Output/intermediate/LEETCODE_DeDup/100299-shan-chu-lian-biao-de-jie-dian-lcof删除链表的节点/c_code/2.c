/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val)
{
    //入参判断
    if(head == NULL)
    {
        return head;
    }

    if(head->val == val)
    {
        head = head->next;
        return head;
    }

    struct ListNode *prev = head;
    struct ListNode *curr = head->next;
    while(curr->val != val)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    return head;
}