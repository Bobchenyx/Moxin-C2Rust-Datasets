/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *newList;
    struct ListNode *auxLeft, *auxRight, *auxParent;   //辅助用
    
    if(head == NULL)
        return NULL;

    newList = head;
    auxLeft = head;
    auxRight = auxLeft->next;
    if(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        newList = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    while(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        auxParent->next = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    return newList;
}