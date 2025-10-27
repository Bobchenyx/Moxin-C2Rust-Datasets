/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *search;
    struct ListNode *mid;
    int mid_data;

    mid = search = head->next;
    if(mid == NULL)
    return head;
    while(search->next != NULL)
    {
        if(search->next->next != NULL)
        {
            search = search->next->next;
            mid = mid->next;
        }
        else
        {
            search = search->next;
        }
    }

    return mid;
}